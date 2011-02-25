(:
 : Copyright 2006-2009 The FLWOR Foundation.
 :
 : Licensed under the Apache License, Version 2.0 (the "License");
 : you may not use this file except in compliance with the License.
 : You may obtain a copy of the License at
 :
 : http://www.apache.org/licenses/LICENSE-2.0
 :
 : Unless required by applicable law or agreed to in writing, software
 : distributed under the License is distributed on an "AS IS" BASIS,
 : WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 : See the License for the specific language governing permissions and
 : limitations under the License.
 :)


(:~
 : Function library providing transformation functions from XQDoc to XHTML.
 :
 : @author Gabriel Petrovay, Sorin Nasoi
 :)
module namespace xqdoc2html  = "http://www.zorba-xquery.com/modules/xqdoc2xhtml/";

import module namespace file = "http://www.zorba-xquery.com/modules/file";
import module namespace xqd  = "http://www.zorba-xquery.com/modules/xqdoc";
import module namespace err  = "http://www.zorba-xquery.com/modules/xqdoc2xhtml/error";

import schema namespace xqdoc = "http://www.xqdoc.org/1.0";

declare copy-namespaces preserve, inherit;

declare namespace output = "http://www.w3.org/2010/xslt-xquery-serialization";

(:~
 : This variable contains all the modules names part of the left menu
 :)
declare variable $xqdoc2html:indexCollector := <modules/>;

(:~
 : This variable contains all the schemas imported by the modules
 :)
declare variable $xqdoc2html:schemasCollector := <schemas/>;

(:~
 : This variable contains all the functions from all imported modules
 :)
declare variable $xqdoc2html:functionsCollector := <functions/>;

(:~
 : This variable contains the links appearing in the first part of the left menu
 : of every XHTML page
 :)
 declare variable $xqdoc2html:externalLinks := 
  <links>
    <a href="http://www.zorba-xquery.com/index.php/tutorials/" 
       title="Tutorials" target="_blank">Tutorials</a>
    <a href="http://experimental.zorba-xquery.org/" 
       title="Get started with XQuery using Zorba"
       target="_blank">Experiment XQuery with Zorba</a>
    <a href="modules.svg" 
       title="Module dependencies SVG graph">Module dependencies SVG graph</a>
  </links>;

(:~
 : This is the name of the function index XHTML page.
 :)
declare variable $xqdoc2html:functionIndexPageName as xs:string := "function_index.html";

(:~
 : This is the name of the search XHTML page.
 :)
declare variable $xqdoc2html:searchPageName as xs:string := "search.html";

(:~
 : The function clears all the files matching $pattern from the provided folderPath.
 :
 : @param $folderPath where to search for modules recursively.
 : @param $pattern where to generate the XQDoc XML documents.
 : @return Empty sequence.
 :)
declare %private sequential function xqdoc2html:clear-folder(
  $folderPath as xs:string, 
  $pattern as xs:string)
{
  if(fn:not(file:exists($folderPath))) then
    ()
  else
    for $file in file:files($folderPath, $pattern, fn:true())
    let $filePath := fn:concat($folderPath, file:path-separator(), $file)
    let $res := file:remove($filePath)
    return
      ()
};

(:~
 : The function gathers all the files matching $pattern from the provided $sourcePath
 : and copies them to $destinationPath. The folder structure is not preserved (all files
 : are saved on the same folder level independent of their source folder structure).
 :
 : @param   $sourcePath where to search for modules recursively.
 : @param   $destinationPath destination folder for the files.
 : @param   $pattern the pattern expressed by XQuery regular expressions.
 : @return  Empty sequence.
 :)
declare %private sequential function xqdoc2html:gather-and-copy(
  $sourcePath       as xs:string,
  $destinationPath  as xs:string, 
  $pattern          as xs:string)
{
  if(fn:not(file:exists($destinationPath))) then
    ()
  else
    for $file in file:files($sourcePath, $pattern, fn:true())
    let $fileName := fn:tokenize($file, fn:concat("\",file:path-separator()))[last()]
    let $fileSourcePath := fn:concat($sourcePath, file:path-separator(), $file)
    let $fileDestinationPath := fn:concat($destinationPath, file:path-separator(), $fileName)
    let $res := file:copy($fileSourcePath, $fileDestinationPath, fn:false())
    return
      ()
};

(:~
 : The function gathers all the files matching $pattern from the provided $sourcePath
 : and copies them to $destinationPath. The folder structure is not preserved.
 :
 : @param   $sourcePath where to search for modules recursively.
 : @param   $destinationPath destination folder for the files.
 : @param   $pattern where to generate the XQDoc XML documents.
 : @return  Empty sequence.
 :)
declare %private sequential function xqdoc2html:copy-files(
  $sourcePath       as xs:string,
  $destinationPath  as xs:string, 
  $pattern          as xs:string)
{
  file:mkdir($destinationPath);

  let $clear := xqdoc2html:clear-folder($destinationPath, $pattern)
  let $clear := xqdoc2html:gather-and-copy($sourcePath, $destinationPath, $pattern)
  return ();
};

(:~
 : Creates the $xqSrcPath folder
 : and gathers all the *.xq.src folders and copies them into the $xqSrcPath folder.
 :
 : @param   $modulePath where to search for *.xq.src folders.
 : @param   $xqSrcPath destination folder for the files in the *.xq.src folders.
 : @return  The function returns a string sequence with a status message for each
 :          copied folder.
 :)
declare %private sequential function xqdoc2html:copy-xqsrc-folders(
  $modulePath as xs:string,
  $xqSrcPath as xs:string)
{
  file:mkdir($xqSrcPath);

  xqdoc2html:clear-folder($xqSrcPath,"(\.cpp|\.h)$");
    
  (: gather all .xq.src folders :)
  let $xqSrcFolders := fn:distinct-values(
    for $file in file:files($modulePath, "(\.cpp|\.h)$", fn:true())
    where ends-with(fn:tokenize($file, fn:concat("\",file:path-separator()))[last()-1],'xq.src')
    return
      substring-before($file,'.xq.src')
  )
  (: create the needed folders in $xqSrcPath and copy all the .cpp and .h into them
    the folder name is the same as the name of the .xml file (without the .xml extension) for that module :)
  for $xqSrcFolder in $xqSrcFolders
  let $xqSrcSourcePath := fn:concat($modulePath, file:path-separator(), $xqSrcFolder, '.xq.src')
  let $xqSrcDestinationPath :=
    fn:concat($xqSrcPath, file:path-separator(),
              xqdoc2html:get-filename(xqdoc2html:get-URI-from-location($xqSrcFolder)))
  let $ret := xqdoc2html:copy-files($xqSrcSourcePath, $xqSrcDestinationPath, "(\.cpp|\.h)$")
  return
    ();
};

(:~
 : The function copies all the files under the following folders 
 : from $xhtmlRequisitesPath to $xqdocBuildPath/xhtml folder:
 : <ul>
 :  <li>schemas</li>
 :  <li>xq.src folders</li>
 :  <li>images</li>
 :  <li>java scripts</li>
 :  <li>css stylesheets</li>
 :  <li>templates</li>
 :  <li>examples</li>
 :  <li>modules</li>
 : </ul>
 :
 : @param $modulesPath location of the modules.
 : @param $xhtmlRequisitesPath the folder containing the images, lib, styles and templates folders.
 : @param $xqdocBuildPath where to generate the XQDoc XML documents.
 : @return Empty sequence.
 :)
declare sequential function xqdoc2html:copy-xhtml-requisites(
  $modulesPath          as xs:string,
  $xhtmlRequisitesPath  as xs:string,
  $xqdocBuildPath       as xs:string)
{
let $xhtmlPath      := fn:concat($xqdocBuildPath, file:path-separator(), "xhtml"),
    $schemasPath    := fn:concat($xhtmlPath,      file:path-separator(), "schemas"),
    $xqSrcPath      := fn:concat($xhtmlPath,      file:path-separator(), "xq.src"),
    $xqPath         := fn:concat($xhtmlPath,      file:path-separator(), "modules"),
    $imagesPath     := fn:concat($xhtmlPath,      file:path-separator(), "images"),
    $libPath        := fn:concat($xhtmlPath,      file:path-separator(), "lib"),
    $cssPath        := fn:concat($xhtmlPath,      file:path-separator(), "css"),
    $templatesPath  := fn:concat($xhtmlPath,      file:path-separator(), "templates"),
    $examplesPath   := fn:concat($xhtmlPath,      file:path-separator(), "examples")

return
  (: first - create the xhtml folder is it does not exist already :)
  file:mkdir($xhtmlPath);

  (: second - clear the folder of all the files with these extensions :)
  let $clear := xqdoc2html:clear-folder($xhtmlPath,"(\.xsd|\.gif|\.js|\.css|\.html|\.cpp|\.h|\.xq)$")
  return (
    (: third - re-copy these files :)
    xqdoc2html:copy-files($modulesPath, $schemasPath, "\.xsd$"),
    xqdoc2html:copy-files($xhtmlRequisitesPath, $imagesPath, "\.gif$"),
    xqdoc2html:copy-files($xhtmlRequisitesPath, $libPath, "\.js$"),
    xqdoc2html:copy-files($xhtmlRequisitesPath, $cssPath, "\.css$"),
    xqdoc2html:copy-files($xhtmlRequisitesPath, $templatesPath, "\.html$"),

    xqdoc2html:copy-xqsrc-folders($modulesPath, $xqSrcPath),

    (: only create the 'modules' folder. The .xq module files will be copied later on in the process :)
    file:mkdir($xqPath),
  
    (: only create the examples folder. The examples will be copied later on in the process :)
    file:mkdir($examplesPath)
  );
};

(:~ Returns the URI of the module given the passed $folderPath using the Zorba URI resolving mechanism.
 :
 : @param $folderPath the folder path.
 : @return the URI of the module.
 :
 :)
declare %private function xqdoc2html:get-URI-from-location($folderPath as xs:string) as xs:string {
  let $tok := tokenize($folderPath, fn:concat("\",file:path-separator()))
  return
    fn:concat('http://', $tok[3],'.', $tok[2],'.', $tok[1], substring-after($folderPath, $tok[3]))
};

(:~ Returns the string resulting from replacing the path-separators (i.e. / ) with '_'
 :
 : @param $moduleURI the path to the module URI.
 : @return the string resulting from replacing the path-separators (i.e. / ) with '_'. 
 :
 :)
declare %private function xqdoc2html:get-filename($moduleURI as xs:string) as xs:string {
  let $lmodule := if(fn:ends-with($moduleURI,"/")) then fn:concat($moduleURI,"index") else $moduleURI
  return
    replace(
      replace($lmodule, "/", "_"),
      "http:__",
      ""
  )
};

declare  %private function xqdoc2html:get-example-filename($examplePath as xs:string) as xs:string 
{
  if(contains($examplePath,"/")) then
    fn:replace($examplePath,"/","_")
  else if (contains($examplePath,"\")) then
    fn:replace($examplePath,"\","_")
  else
    $examplePath
};

declare  %private function xqdoc2html:get-example-filename-link($examplePath as xs:string) as xs:string 
{
  fn:tokenize($examplePath,fn:concat("\",file:path-separator()))[last()]
};


(:~
 : This function generates the XQDoc XML for all the modules found in $modulesPath
 : and writes the resulting XML documents in $targetPath. The hierarchy is not preserved.
 :
 : @param $modulePath where to search for modules recursively.
 : @param $xqdocXmlPath where to generate the XQDoc XML documents.
 : @param $xqdocXhtmlPath where to generate the XQDoc XHTML documents.
 : @param $examplePath string with the paths where the examples are kept separated by ; .
 : @return A string sequence with a status message for each processed module.
 :)
declare sequential function xqdoc2html:generate-xqdoc-xml(
  $modulesPath as xs:string,
  $xqdocXmlPath as xs:string,
  $xqdocXhtmlPath as xs:string,
  $examplePath as xs:string) as xs:string* {
  for $filedirs in tokenize($modulesPath, ";")
  for $file in file:files($filedirs, "\.xq$", fn:true())
  let $filePath := fn:concat($filedirs, file:path-separator(), $file)
  let $xqdoc := xqd:xqdoc(file:path-to-uri($filePath))
  let $xqdoc := xqdoc2html:configure-xml($xqdoc, $examplePath, $xqdocXhtmlPath)
  let $moduleDoc := $xqdoc/xqdoc:module
  let $moduleName := $moduleDoc/xqdoc:name
  let $moduleUri := $moduleDoc/xqdoc:uri
  return
    try {
      let $x := fn:count(file:files($xqdocXmlPath, "\.xml$", fn:true())) + 1
      let $getFilename := xqdoc2html:get-filename($moduleUri)
      let $xqdocFileName := fn:concat($xqdocXmlPath, file:path-separator(), $getFilename, ".xml")
      let $xhtmlRelativeFilePath :=fn:concat($getFilename, ".html")
      let $ret := file:write($xqdocFileName, $xqdoc, <s method="xml" indent="yes" />/@*)
      let $hasExtFuncs := xqdoc2html:contains-external-functions($xqdoc)
      
      return
        if($xqdoc/xqdoc:module/@type = "library") then
        (
          xqdoc2html:collect-module($moduleUri/text(), $getFilename, $hasExtFuncs, $xqdoc2html:indexCollector),
          
          xqdoc2html:collect-functions($xqdoc, $xhtmlRelativeFilePath, $xqdoc2html:functionsCollector),
          
          (:copy the actual module under xhtml/modules folder but save it under a different name, i.e. $xhtmlRelativeFilePath :)
          let $ret := file:copy($filePath,
                                fn:concat($xqdocXhtmlPath,
                                          file:path-separator(),
                                          "modules",
                                          file:path-separator(),
                                          $getFilename,
                                          ".xq"), 
                                fn:false())
          return ()
        )
        else
         ()    
    } catch * ($error_code) 
    {      
      fn:error($err:UE004, fn:concat("FAILED: ", $moduleUri, " (", fn:concat($xqdocXmlPath, file:path-separator(), xqdoc2html:get-filename($moduleUri), ".xml"), ")"));
    }
};


(:~
 : This function generates the XQDoc XHTML pages for all the XQDoc XML
 : documents found in $xqdocPath and writes the resulting pages to $targetPath. 
 : The hierarchy is not preserved. 
 :
 : @param $xqdocXmlPath path to the XQDoc XML files.
 : @param $xqdocXhtmlPath location where the resulting Xhtml will be saved on disk.
 : @param $xqSrcPath location of the xq.src folder containing the implementation of the external functions.
 : @param $leftMenu the menu containing the links to the generated Xhtml files.
 : @param $modulesPath the path to the .xq modules.
 : @param $functionIndexPageName the name of the generated page for the function index.
 : @param $templatePath the path to the main.html template.
 : @param $examplePath string with the paths where the examples are kept separated by ; .
 : @return a string sequence with the status of every processed XQDoc XML file.
 :)
declare %private sequential function xqdoc2html:generate-xqdoc-xhtml(
  $xqdocXmlPath           as xs:string,
  $xqdocXhtmlPath         as xs:string, 
  $xqSrcPath              as xs:string,
  $leftMenu               as element(menu),
  $modulesPath            as xs:string, 
  $functionIndexPageName  as xs:string,
  $templatePath           as xs:string,
  $examplePath            as xs:string) as xs:string* {
  for $file in file:files($xqdocXmlPath, "\.xml$", fn:true())
  let $xmlFilePath := concat($xqdocXmlPath, file:path-separator(), $file)
  let $xhtmlFilePath := concat($xqdocXhtmlPath, file:path-separator(), fn:replace($file, "\.xml$", ".html"))
  let $xhtmlFileDir := 
    let $segments := fn:tokenize($xhtmlFilePath, fn:concat("\", file:path-separator()))
    let $lastSegm := $segments[fn:count($segments)] 
    return fn:substring-before($xhtmlFilePath, $lastSegm)
  return
    try {
      let $xqdoc := file:read-xml($xmlFilePath)/xqdoc:xqdoc
      let $moduleDoc := $xqdoc/xqdoc:module
      let $moduleName := $moduleDoc/xqdoc:name
      let $moduleUri := $moduleDoc/xqdoc:uri
      let $menu := xqdoc2html:create-left-menu($leftMenu, $moduleUri)
      let $menu := xqdoc2html:create-module-table($leftMenu, $menu, $moduleUri)
      let $xhtml := xqdoc2html:doc($xqdoc, $menu, $xqdoc2html:indexCollector, $xqdoc2html:schemasCollector, $xqSrcPath, $templatePath, $xqdocXhtmlPath, $examplePath)
      return block {
        file:mkdir($xhtmlFileDir);

        xqdoc2html:configure-xhtml($xhtml, $modulesPath);

        file:write($xhtmlFilePath, $xhtml, <s method="xhtml" indent="yes" />/@*);
      }
    } catch * ($error_code) {
      fn:error($err:UE007, fn:concat("xqdoc2html:generate-xqdoc-xhtml ", $xmlFilePath, " ", $error_code, " " ,$xhtmlFilePath));
    }
};

(:~
 : This function generates the XQDoc function index page.
 : @param $indexFunctionLeft the menu containing the links to the generated Xhtml files.
 : @param $templatePath the path to the main.html template.
 : @return The content of the function index page.
 :)
declare sequential function xqdoc2html:generate-function-index-xhtml(
  $indexFunctionLeft,
  $templatePath as xs:string
) as document-node() {

  let $indexHtmlDoc := file:read-xml($templatePath)
  return block {
      insert node <title>Function index</title>
      as first into $indexHtmlDoc/*:html/*:head;

      insert nodes $indexFunctionLeft
      as last into $indexHtmlDoc/*:html/*:body/*:div[@id='main']/*:div[@id='leftMenu'];

      let $right_content := $indexHtmlDoc/*:html/*:body/*:div[@id='main']/*:div[@id='rightcontent']
      return
        if ($right_content)
        then
          insert nodes
            (<div class="section"><span id="module_description">Indexed Library Module Functions</span></div>,
            xqdoc2html:generate-function-index())
          as last into $right_content
        else
          ();

    $indexHtmlDoc;
  }
};

(:~
 : This function generates the Search page XHTML.
 : @param $indexFunctionLeft the menu containing the links to the generated Xhtml files.
 : @param $templatePath the path to the main.html template.
 : @param $zorbaVersion Zorba version.
 : @return The content of the Search page.
 :)
declare sequential function xqdoc2html:generate-search-xhtml(
  $indexFunctionLeft,
  $templatePath as xs:string,
  $zorbaVersion as xs:string
) as document-node() {

  let $searchDoc := file:read-xml($templatePath)
  return block {
      insert node <title>Search</title>
      as first into $searchDoc/*:html/*:head;

      insert nodes $indexFunctionLeft
      as last into $searchDoc/*:html/*:body/*:div[@id='main']/*:div[@id='leftMenu'];

      insert nodes
           (<script src="http://www.google.com/jsapi" type="text/javascript"></script>,
            <script type="text/javascript">
            google.load('search', '1', &#123; language : 'en'&#125;);
            google.setOnLoadCallback(function() &#123;
              var customSearchControl = new google.search.CustomSearchControl('001923125976056611009:rghy-r4to5y');
              customSearchControl.setResultSetSize(google.search.Search.FILTERED_CSE_RESULTSET);
              var options = new google.search.DrawOptions();
              options.setSearchFormRoot('searchbox');
              customSearchControl.draw('searchresults', options);
            &#125;, true);</script>,
            <link rel="stylesheet" href="http://www.google.com/cse/style/look/minimalist.css" type="text/css" />)
      as first into $searchDoc/*:html/*:body;

      let $right_content := $searchDoc/*:html/*:body/*:div[@id='main']/*:div[@id='rightcontent']
      return
        if ($right_content)
        then
          insert nodes
            (<div class="section"><span id="search">Zorba XQuery Processor {$zorbaVersion} search page</span></div>,
             <div id="searchbox"></div>,
             <div id="searchresults"></div>)
          as last into $right_content
        else
          ();

    $searchDoc;
  }
};

(:~
 : This function gathers schemas found in the $xqdocSchemasPath and fills the $xqdoc2html:schemasCollector.
 : @param $xqdocSchemasPath the path where the schemas are stored.
 : @return a string sequence indicating the result of every processed schema.
 :)
declare %private sequential function xqdoc2html:gather-schemas(
  $xqdocSchemasPath as xs:string) as xs:string* {
  
  for $filedirs in $xqdocSchemasPath
  for $file in file:files($filedirs, "\.xsd$", fn:false())
  let $xsdFilePath := concat($xqdocSchemasPath, file:path-separator(), $file)
  let $xqdRelFilePath := concat(tokenize($xqdocSchemasPath,fn:concat("\",file:path-separator()))[last()],
                                file:path-separator(), $file)
  return
    try {
      let $xqdoc := file:read-xml($xsdFilePath)
      let $xsdUri := $xqdoc/xs:schema/@targetNamespace
      return
          xqdoc2html:collect-schema($xsdUri, $xqdRelFilePath, $xqdoc2html:schemasCollector);
    } catch * ($error_code) {
      fn:error($err:UE005, fn:concat("xqdoc2html:gather-schemas ", $xsdFilePath));
    } 
};

(:~
 : This function adds a new record into the $collector.
 : @param $moduleURI the module URI.
 : @param $relativeFileName the relative path to the module.
 : @param $collector the name of the collector.
 : @return empty sequence.
 :)
declare %private sequential function xqdoc2html:collect-schema (
  $moduleURI as xs:string, 
  $relativeFileName as xs:string, 
  $collector) 
{
  insert node <module uri="{$moduleURI}" file="{$relativeFileName}" /> as last into $collector;
};

(:~
 : This function returns true if there are external functions declared.
 : @param $xqdoc the xqdoc functions.
 : @return a xs:boolean if there are external functions declared.
 :)
declare %private sequential function xqdoc2html:contains-external-functions (
  $xqdoc) as xs:boolean 
{
  let $ext := count(for $sig in $xqdoc/xqdoc:functions/xqdoc:function/xqdoc:signature
                    return
                      if(ends-with($sig/text(),'external')) then 1
                      else ())
  let $func := count ($xqdoc/xqdoc:functions/xqdoc:function/xqdoc:signature)
  return
    (($func gt 0) and ($ext gt 0))  
};

(:~
 : This function adds a new record into the $collector.
 : @param $moduleURI the module URI.
 : @param $relativeFileName the relative path to the module.
 : @param $collector the name of the collector.
 : @param $containsExternalFuncs true is the module contails external functions.
 : @return empty sequence.
 :)
declare %private sequential function xqdoc2html:collect-module (
  $moduleURI as xs:string, 
  $relativeFileName as xs:string, 
  $containsExternalFuncs as xs:boolean,
  $collector) 
{
  insert node <module uri="{$moduleURI}" file="{$relativeFileName}" pureXQuery="{not($containsExternalFuncs)}"/> as last into $collector;
};

(:~
 : This function adds a new record into the $collector.
 : @param $xqdoc the XQDoc xml node.
 : @param $relativeFileName the relative path to the module.
 : @param $collector the name of the collector.
 : @return empty sequence.
 :)
declare %private sequential function xqdoc2html:collect-functions (
  $xqdoc,
  $relativeFileName as xs:string,
  $collector)
{
  block {
    insert nodes
      for $function in $xqdoc/xqdoc:functions/xqdoc:function
      let $name := $function/xqdoc:name/text(),
          $signature := $function/xqdoc:signature/text(),
          $arity := $function/@arity,
          $isDeprecated := fn:exists($function/xqdoc:comment/xqdoc:deprecated)
      (: use only the functions not marked as %private:)
      where (not(exists($function/@isPrivate)) or 
             (exists($function/@isPrivate) and $function/@isPrivate ne "true"))
      order by $name, $arity
      return
        <function moduleUri="{$xqdoc/xqdoc:module/xqdoc:uri/text()}"
                  file="{$relativeFileName}"
                  name="{$function/xqdoc:name/text()}"
                  signature="{$function/xqdoc:signature/text()}"
                  arity="{$arity}"
                  isDeprecated="{fn:exists($function/xqdoc:comment/xqdoc:deprecated)}"/>
    as last into $collector;
    
   };
     
   $collector;
};

(:~
 : This function generates the XQDoc function index.
 : @return Xhtml section with the function index content.
 :)
declare function xqdoc2html:generate-function-index()
{
<div id="level1"><span class="index">
{
  let $alphabet := ("A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z")
  let $letters := distinct-values(
                  for $function in $xqdoc2html:functionsCollector//function
                  return upper-case(substring($function/@name,1,1)))
  return
    (for $letter in $alphabet
    order by $letter
    return
      if(exists(index-of($letters,$letter))) then
        <span class="link"><a href="#{$letter}">{$letter}</a></span>
      else
        <span>{upper-case($letter)}</span>,
     
    for $letter in $letters
      order by $letter
      return
      (<table class="letter">
         <tr>
           <td class="left"><h2><a name="{$letter}">{$letter}</a></h2></td>
           <td class="right"><a href="#module_description" title="Up">Up</a></td>
         </tr>
       </table>,
       <hr />,
        <table class="funclist">
          {
          for $func in $xqdoc2html:functionsCollector//function
          let $moduleUri := fn:data($func/@moduleUri),
              $file := fn:data($func/@file),
              $functionName := fn:data($func/@name),
              $signature := fn:data($func/@signature),
              $arity := fn:data($func/@arity),
              $isDeprecated := fn:data($func/@isDeprecated),
              $isExternal := ends-with($signature, "external"),
              $paramsAndReturn :=
                let $searchCrit := concat(":", $functionName)
                return
                  if ($isExternal)then
                    normalize-space(substring-before(substring-after($signature, $searchCrit), "external"))
                  else normalize-space(substring-after($signature, $searchCrit))
            where starts-with($functionName, lower-case($letter))
            order by $functionName, $arity
            return
              <tr>
                <td><div class="link">
                  <tt>{
                    if ($isDeprecated = "true") then
                      <del><a href="{$file}#{$functionName}-{$arity}">{$functionName}</a></del>
                    else
                      <a href="{$file}#{$functionName}-{$arity}">{$functionName}</a>
                  }{$paramsAndReturn}<br /><span class="padding">Module Namespace: {$moduleUri}</span></tt></div>
                </td>
              </tr>
          }
        </table>
     )
     )
}
</span>
</div>
};

(:~
 : This function returns the file path of the provided file name.
 : @param $filename the module file name.
 : @param $examplePath string with the paths where the examples are kept separated by ; .
 : @return the file path to the provided file name or the empty sequence if the file name was not found.
 :)
declare %private sequential function xqdoc2html:get-example-path (
  $filename as xs:string,
  $examplePath as xs:string
) as xs:string {
  (: $examplePath is zorba_folder/test:)
  let $test := fn:concat($examplePath,file:path-separator(),$filename)
  return
    if (fn:exists($test)) then
      $test
    else 
      fn:error($err:UE008, fn:concat("The example '", $test, "' was not found."));
};

(:~
 : This function does some additional processing for the $xml like
 : replacing examples with actual links to files.
 :
 : @param $xqdoc the node containing the XQDoc XML.
 : @param $examplePath string with the paths where the examples are kept separated by ; .
 : @param $xqdocXhtmlPath where to generate the XQDoc XHTML documents.
 : @return the processed $xhtml.
 :)
declare %private sequential function xqdoc2html:configure-xml (
  $xqdoc,
  $examplePath as xs:string,
  $xqdocXhtmlPath as xs:string) {
    
  (: copy the example into the 'examples' folder :)
  xqdoc2html:copy-examples($xqdoc, $xqdocXhtmlPath, $examplePath);

  (: replace the inlineExamples with actual inline code :)

  for $inlineExample in $xqdoc//*:inlineexample
  let $exampleSource := xqdoc2html:get-example-path(data($inlineExample/@href),$examplePath)
  let $exampleContent := file:read-text( $exampleSource )
  return
    replace node $inlineExample with
      <pre class="brush: xquery;">{text{$exampleContent(:$inlineExample/@href:)}}</pre>;
 
  $xqdoc;
};

(:~
 : This function does some additional processing for the $xhtml like
 : replacing the function type description with images, 
 : replacing the function names description with images+name of the functions.
 : @param $xhtml the node containing the XHTML file.
 : @param $modulesPath the path where the .xq modules are stored on disk.
 : @return the processed $xhtml.
 :)
declare sequential function xqdoc2html:configure-xhtml (
  $xhtml,
  $modulesPath as xs:string 
) {

  (: replace the function type description with images :)
  let $xquSpec := "http://www.w3.org/TR/xquery-update-10/",
      $xqsSpec := "http://www.w3.org/TR/xquery-sx-10/#dt-sequential-function",
      $xq11Spec := "http://www.w3.org/TR/xquery-11/#FunctionDeclns",
      $xqExternal := "http://www.w3.org/TR/xquery-30/#dt-external-function"
  let $imagesPath := "images/"
  for $typeTd in $xhtml//*:td
  where $typeTd/@class eq "type"
  let $type := $typeTd/text()
  return block {
    if (matches($type, "updating")) then
      replace node $typeTd/text() with
        <a href="{$xquSpec}" title="{$type}" target="_blank"><img src="{concat($imagesPath, "U.gif")}" /></a>
    else if (matches($type, "sequential")) then
      replace node $typeTd/text() with
        <a href="{$xqsSpec}" title="{$type}" target="_blank"><img src="{concat($imagesPath, "S.gif")}" /></a>
    else if (matches($type, "nondeterministic")) then
      replace node $typeTd/text() with
        <a href="{$xq11Spec}" title="{$type}" target="_blank"><img src="{concat($imagesPath, "N.gif")}" /></a>
    else if (matches($type, "external")) then
      replace node $typeTd/text() with
        <a href="{$xqExternal}" title="{$type}" target="_blank"><img src="{concat($imagesPath, "E.gif")}" /></a>    
    else ();
  };
  
  (: replace the function names description with images+name of the functions :) 
  let $xquSpec :=  "http://www.w3.org/TR/xquery-update-10/",
      $xqsSpec :=  "http://www.w3.org/TR/xquery-sx-10/#dt-sequential-function",
      $xq11Spec := "http://www.w3.org/TR/xquery-11/#FunctionDeclns",
      $xqExternal := "http://www.w3.org/TR/xquery-30/#dt-external-function"
  let $imagesPath := "images/"
  for $func in $xhtml//*:div
  where $func/@class eq "subsection"
  let $funcName := $func/text()
  return block {
    if (starts-with($funcName, "updating")) then
      replace node $func/text() with
        <span class="no_underline">
          <a href="{$xquSpec}" title="updating" target="_blank"><img src="{concat($imagesPath, "U.gif")}" /></a>
          {text {substring-after(substring-before($funcName," external"), "updating")}}
          {if(ends-with($funcName, " external")) then
            <a href="{$xqExternal}" title="external" target="_blank"><img src="{concat($imagesPath, "E.gif")}" /></a>
          else ()}
        </span>
        
    else if (starts-with($funcName, "sequential")) then
      replace node $func/text() with
        <span class="no_underline">
          <a href="{$xqsSpec}" title="sequential" target="_blank"><img src="{concat($imagesPath, "S.gif")}" /></a>
          {text {substring-after(substring-before($funcName," external"), "sequential")}}
          {if(ends-with($funcName, " external")) then
            <a href="{$xqExternal}" title="external" target="_blank"><img src="{concat($imagesPath, "E.gif")}" /></a>
          else ()}
        </span>
        
    else if (starts-with($funcName, "nondeterministic")) then
      replace node $func/text() with
        <span class="no_underline">
          <a href="{$xq11Spec}" title="nondeterministic" target="_blank"><img src="{concat($imagesPath, "N.gif")}" /></a>
          {text {substring-after(substring-before($funcName," external"), "nondeterministic")}}
          {if(ends-with($funcName, " external")) then
            <a href="{$xqExternal}" title="external" target="_blank"><img src="{concat($imagesPath, "E.gif")}" /></a>
          else ()}
        </span>
    else if(ends-with($funcName, " external")) then
      replace node $func/text() with
        <span class="no_underline">
          {text {substring-before($funcName," external")}}
          <a href="{$xqExternal}" title="external" target="_blank"><img src="{concat($imagesPath, "E.gif")}" /></a>
        </span>
    else ();
  };
   
  $xhtml;
};

(:~
 : This function creates the categories in the menu.
 :
 : @param $leftMenu the menu.
 : @param $root the root.
 : @param $moduleUri module URI.
 : @return $root after the subcategories were added to it.
 :)
declare %private sequential function xqdoc2html:create-module-table(
  $leftMenu as element(menu), 
  $root, 
  $moduleUri) { 
  for $cat1 in $leftMenu/category
  return block {
    xqdoc2html:create-module-helper($root, $cat1, $moduleUri);
    for $cat2 in $cat1/category
    let $table2 := $root/li[fn:last()]/ul
    return block {
      xqdoc2html:create-module-helper($table2, $cat2, $moduleUri);
      for $cat3 in $cat2/category
      let $table3 := $root/li[fn:last()]/ul/li[fn:last()]/ul
      return block {
        xqdoc2html:create-module-helper($table3, $cat3, $moduleUri);
      };
    };
  };
  
  $root;
};

(:~
 : This function creates menu header provided $pageName page.
 :
 : @param $leftMenu the menu.
 : @param $pageName the name of the function index XHTML page.
 : @return $root after the subcategories were added to it.
 :)
declare %private function xqdoc2html:create-left-menu(
  $leftMenu as element(menu),
  $pageName as xs:string) {
  <ul id="documentation">
    {
    (
      if($pageName = $xqdoc2html:functionIndexPageName) then
        (
        <span><a href="index.html">{string($leftMenu/@title)}</a></span>,    
        <li><span class="leftmenu_active">Function Index</span></li>,
        <li><a href="{$xqdoc2html:searchPageName}">Search page</a></li>)
      else if($pageName = "index.html") then
        (<span class="leftmenu_active">{string($leftMenu/@title)}</span>,
         <li><a href="{$xqdoc2html:functionIndexPageName}">Function Index</a></li>,
         <li><a href="{$xqdoc2html:searchPageName}">Search page</a></li>)
      else if($pageName = $xqdoc2html:searchPageName) then
        (<span><a href="index.html">{string($leftMenu/@title)}</a></span>,
         <li><a href="{$xqdoc2html:functionIndexPageName}">Function Index</a></li>,
         <li><span class="leftmenu_active">Search page</span></li>)
      else
         (<span><a href="index.html">{string($leftMenu/@title)}</a></span>,
         <li><a href="{$xqdoc2html:functionIndexPageName}">Function Index</a></li>,
         <li><a href="{$xqdoc2html:searchPageName}">Search page</a></li>),
      
      for $link in $xqdoc2html:externalLinks//a
      return
        <li>{$link}</li>
    )
    }
   </ul>
};

(:~
 : This function add the subcategories in the menu.
 :
 : @param $table the parent module category.
 : @param $category the category.
 : @param $moduleUri module URI.
 : @return $table after the subcategory together with the modules were added to it.
 :)
declare %private sequential function xqdoc2html:create-module-helper(
  $table, 
  $category, 
  $moduleUri)
{
  block {
    insert nodes <li>{data($category/@name)}
    <ul>
    {
      for $module in $xqdoc2html:indexCollector/module
      let $lModuleUri := data($module/@uri)
      let $lCatUri := data($category/@uri)
      let $lPureXquery := xs:boolean(data($module/@pureXQuery))
      order by $lModuleUri
      return
        if(fn:starts-with($lModuleUri, $lCatUri)
           and fn:not(fn:contains (fn:substring-after($lModuleUri,fn:concat($lCatUri,'/')),'/'))) then
        (
          let $uri := if(fn:substring-after($lModuleUri, $lCatUri) = "") then
                        "index"
                      else if (fn:ends-with($lCatUri,"/")) then
                        fn:substring-after($lModuleUri, $lCatUri)
                      else
                        fn:substring-after($lModuleUri, fn:concat($lCatUri,"/"))
          
          return
            if($lModuleUri = $moduleUri) then
              <li>
                <span class="leftmenu_active">{$uri}
                {
                  if($lPureXquery) then  ()
                  else
                    <span class="superscript"><a href="http://www.w3.org/TR/xquery-30/#dt-external-function" target="_blank" title="There are external functions (either private or public) declared in this module.">(E)</a></span>
                }
                </span>
              </li>
            else 
              <li>
                <a href="{$module/@file}.html">{$uri}</a>
                {
                  if($lPureXquery) then ()
                  else
                    <span class="superscript"><a href="http://www.w3.org/TR/xquery-30/#dt-external-function" target="_blank" title="There are external functions (either private or public) declared in this module.">(E)</a></span>
                }
              </li>
        )
        else ()
    }    
    </ul></li>
    as last into $table
  };

  $table;
};

(:~
 : This function reads, updates and returns the new index.html.
 :
 : @param $templatePath the path to the 'main.html' template.
 : @param $menu the menu.
 : @param $modules the modules.
 : @param $zorbaVersion Zorba version.
 : @return The content of the new index.html.
 :)
declare %private sequential function xqdoc2html:generate-index-html(
  $templatePath as xs:string, 
  $menu, 
  $modules,
  $zorbaVersion as xs:string) as document-node() {
    let $indexHtmlDoc := file:read-xml($templatePath)
    return block {
        insert node <title>XQuery Modules Documentation</title>
        as first into $indexHtmlDoc/*:html/*:head;

        insert nodes $menu
        as last into $indexHtmlDoc/*:html/*:body/*:div[@id='main']/*:div[@id='leftMenu'];

        let $right_content := $indexHtmlDoc/*:html/*:body/*:div[@id='main']/*:div[@id='rightcontent']
        return
          if ($right_content)
          then
            insert nodes
              (<div class="section"><span class="section">XQuery Modules Documentation for Zorba XQuery Processor {$zorbaVersion}</span></div>,
              <p>This document contains a list of all the XQuery modules that come with the Zorba XQuery processor.</p>,
              $modules)
            as last into $right_content
          else
            ();

        $indexHtmlDoc;
    }
};


(:~
 : This function creates the XQDoc XMLs and from them the XQDoc XHTMLs.
 :
 : @param $modulePath where to search for .xq modules recursively.
 : @param $xqdocBuildPath where to output the XQDoc XMLs and XHTMLs.
 : @param $xhtmlRequisitesPath where to search for the XHTML requisites.
 : @param $examplePath string with the paths where the examples are kept separated by ; .
 : @param $zorbaVersion Zorba version.
 : @return Empty sequence.
 :)
declare sequential function xqdoc2html:main(
  $modulePath as xs:string, 
  $xqdocBuildPath as xs:string,
  $xhtmlRequisitesPath as xs:string,
  $examplePath as xs:string,
  $zorbaVersion as xs:string
) {
    let $leftMenu :=
    <menu title="XQuery Modules Documentation">
      <category name="http://expath.org/ns" uri="http://expath.org/ns" />
      <category name="http://www.zorba-xquery.com/modules" uri="http://www.zorba-xquery.com/modules" >
        <category name="convertors" uri="http://www.zorba-xquery.com/modules/convertors" />
        <category name="data-cleaning" uri="http://www.zorba-xquery.com/modules/data-cleaning" />
        <category name="email" uri="http://www.zorba-xquery.com/modules/email" />
        <category name="excel" uri="http://www.zorba-xquery.com/modules/excel" />
        <category name="image" uri="http://www.zorba-xquery.com/modules/image" />
        <category name="introspection" uri="http://www.zorba-xquery.com/modules/introspection" />
        <category name="security" uri="http://www.zorba-xquery.com/modules/security" />
        <category name="oauth" uri="http://www.zorba-xquery.com/modules/oauth" />
        <category name="webservices" uri="http://www.zorba-xquery.com/modules/webservices" >
          <category name="google" uri="http://www.zorba-xquery.com/modules/webservices/google" />
          <category name="yahoo" uri="http://www.zorba-xquery.com/modules/webservices/yahoo" />
        </category>
        <category name="xqdoc2xhtml" uri="http://www.zorba-xquery.com/modules/xqdoc2xhtml/" />
      </category>
      <category name="http://www.w3.org/2005" uri="http://www.w3.org/2005" />
      <category name="www.functx.com" uri="http://www.functx.com/" />
    </menu>
    let $indexHtmlPath as xs:string := fn:concat($xhtmlRequisitesPath, file:path-separator(), "templates", file:path-separator(), "index.html")
    return xqdoc2html:main($leftMenu, $modulePath, $xqdocBuildPath, $indexHtmlPath, $examplePath, $zorbaVersion)
};

(:~
 : This function creates the XQDoc XMLs and from them the XQDoc XHTMLs.
 :
 : @param $leftMenu the menu containing the links to the generated XHTMLs.
 : @param $modulePath where to search for .xq modules recursively.
 : @param $xqdocBuildPath where to output the XQDoc XMLs and XHTMLs.
 : @param $indexHtmlPath where to load the template for the index.html.
 : @param $examplePath string with the paths where the examples are kept separated by ; .
 : @param $zorbaVersion Zorba version.
 : @return Empty sequence.
 :)
declare %private sequential function xqdoc2html:main(
  $leftMenu as element(menu),
  $modulePath as xs:string, 
  $xqdocBuildPath as xs:string,
  $indexHtmlPath as xs:string,
  $examplePath as xs:string,
  $zorbaVersion as xs:string
) {  
  declare $xqdocXmlPath     as xs:string := fn:concat($xqdocBuildPath, file:path-separator(), "xml");
  declare $xqdocXhtmlPath   as xs:string := fn:concat($xqdocBuildPath, file:path-separator(), "xhtml");
  declare $xqdocSchemasPath as xs:string := fn:concat($xqdocXhtmlPath, file:path-separator(), "schemas");
  declare $xqSrcPath        as xs:string := fn:concat($xqdocXhtmlPath, file:path-separator(), "xq.src");
  declare $templatesPath    as xs:string := fn:concat($xqdocXhtmlPath, file:path-separator(), "templates");
  declare $templatePath     as xs:string :=
    fn:concat($templatesPath, file:path-separator(), file:files($templatesPath, "(main\.html)$", fn:true()));

  (: if there is no main.html template we can not proceed further :)
  if($templatePath = fn:concat($templatesPath, file:path-separator())) then
    fn:error($err:UE002, "No 'main.html' template was found.")
  else
    ();
  
  (: generate the XQDoc XML for all the modules :)
  file:mkdir($xqdocXmlPath);
  xqdoc2html:clear-folder($xqdocXmlPath,"\.xml$");
  xqdoc2html:generate-xqdoc-xml($modulePath, $xqdocXmlPath, $xqdocXhtmlPath, $examplePath);
    
  (: generate the XQDoc XHTML for all the modules :) 
  let $absoluteXhtmlDir := concat($xqdocBuildPath, "/xhtml")
  return
    block {
      file:mkdir($absoluteXhtmlDir);
      xqdoc2html:clear-folder($xqdocXhtmlPath,"xqdoc\.html$");
      xqdoc2html:gather-schemas($xqdocSchemasPath);
      xqdoc2html:generate-xqdoc-xhtml($xqdocXmlPath, $xqdocXhtmlPath, $xqSrcPath, $leftMenu, $modulePath, $xqdoc2html:functionIndexPageName, $templatePath, $examplePath);

      let $leftMenuFunction := xqdoc2html:create-left-menu($leftMenu, $xqdoc2html:functionIndexPageName)
      let $indexFunctionLeft := xqdoc2html:create-module-table($leftMenu, $leftMenuFunction, $xqdoc2html:functionIndexPageName)
      let $leftMenuSearch := xqdoc2html:create-left-menu($leftMenu, $xqdoc2html:searchPageName)
      let $indexSearchLeft := xqdoc2html:create-module-table($leftMenu, $leftMenuSearch, $xqdoc2html:searchPageName)

      let $functionIndex := xqdoc2html:generate-function-index-xhtml($indexFunctionLeft, $templatePath)
      let $search := xqdoc2html:generate-search-xhtml($indexSearchLeft, $templatePath, $zorbaVersion)
      
      let $writeFuncIndex := file:write(fn:concat($xqdocXhtmlPath, file:path-separator(), $xqdoc2html:functionIndexPageName), $functionIndex, <s method="xhtml" indent="yes" />/@*)
      let $writeFuncIndex := file:write(fn:concat($xqdocXhtmlPath, file:path-separator(), $xqdoc2html:searchPageName), $search, <s method="xhtml" indent="yes" />/@*)
      return
        ();
    };  
  
  let $left := xqdoc2html:create-left-menu($leftMenu, "index.html")
  let $indexLeft := xqdoc2html:create-module-table($leftMenu, $left, "index.html")
  let $right := <ul />
  let $indexRight := xqdoc2html:create-module-table($leftMenu, $right, "index.html")
  let $doc := xqdoc2html:generate-index-html($templatePath, $indexLeft, $indexRight, $zorbaVersion)
  let $index := xqdoc2html:configure-xhtml($doc/*:html, $modulePath)
  let $writeIndex := file:write(fn:concat($xqdocXhtmlPath, file:path-separator(), "index.html"), $index, <s method="xhtml" indent="yes" />/@*)
  return
    ()
  ;
 
};

(: ******************  Functions that create the content of the XHTML pages  ************************:)

(:~
 : This method copies all the examples and inlineexamples to the $xqdocXhtmlPath/examples folder.
 :
 : @param $xqdoc the node containing the XQDoc XML.
 : @param $xqdocXhtmlPath location where the resulting Xhtml will be saved on disk.
 : @param $examplePath string with the paths where the examples are kept separated by ; .
 : @return The created XHTML page.
 :)
declare sequential function xqdoc2html:copy-examples(
  $xqdoc, 
  $xqdocXhtmlPath as xs:string,
  $examplePath as xs:string) {
  
  (:copy the @examples:)
  let $xqdocExamplesPath := fn:concat($xqdocXhtmlPath, file:path-separator(), "examples")
  return block {
  for $example in $xqdoc/xqdoc:functions/xqdoc:function/xqdoc:comment/xqdoc:example
  let $exampleText := xqdoc2html:get-example-filename($example/text())
  let $exampleSource := xqdoc2html:get-example-path($example/text(),$examplePath)
  let $exampleDestination := fn:concat($xqdocExamplesPath, file:path-separator(), $exampleText)
  return
    try {
    if(exists($exampleSource)) then
    (
      file:copy($exampleSource, $exampleDestination, fn:false())
 (:     
      (:append the expected result if example is .xq, it doesn't contain "output" and it doesn't have a spec file:)
      let $specSource := fn:replace($exampleSource, "[.]xq$", ".spec")
	    let $specContent := if(fn:matches($specSource, "[.]spec$") and file:is-file($specSource)) then file:read-text( $specSource ) else ""
      return
      if(fn:not( matches($specContent, "Error")) and fn:not(matches($specContent, "Args")) ) then
        let $exampleContent := file:read-text( $exampleDestination )
        return
        if(fn:not(fn:matches($exampleContent, "output", "i"))) then
          let $search-queries := fn:concat("rbkt[", file:path-separator(), file:path-separator(), "//]Queries")
          let $replace-exp-result := "rbkt/ExpQueryResults"
          let $exp-result-path := fn:replace($exampleSource, $search-queries, $replace-exp-result)
          let $exp-result := fn:replace($exp-result-path, "[.]xq$", ".xml.res")
          return
          if(($exp-result-path ne $exampleSource) and file:is-file ( $exp-result )) then
            let $output-content := file:read-text ( $exp-result )
            let $new-content := fn:concat ($exampleContent, "
"           )
            return
            file:write( $exampleDestination, $new-content, <output:method>text</output:method>)
          else
          ()
        else
        ()
      else
      ():)
    )
      else
        fn:error($err:UE008, fn:concat("Example <'", $exampleSource,"> does not exist."));
    }
    catch * ($error_code)
    {
      fn:error($err:UE008, fn:concat("Copy example from <", $exampleSource,"> to <", $exampleDestination, "> failed."));
    }
  }
};

(:~
 : This function creates the XQDoc XHTML.
 :
 : @param $xqdoc the node containing the XQDoc XML.
 : @param $menu the menu.
 : @param $indexCollector the modules names part of the left menu.
 : @param $schemasCollector the schemas imported by the modules.
 : @param $xqSrcPath the path to the xq.src folders.
 : @param $templatePath the path to the main.html template.
 : @param $xqdocXhtmlPath location where the resulting Xhtml will be saved on disk.
 : @param $examplePath string with the paths where the examples are kept separated by ; .
 : @return The created XHTML page.
 :)
declare sequential function xqdoc2html:doc(
  $xqdoc, 
  $menu, 
  $indexCollector, 
  $schemasCollector, 
  $xqSrcPath as xs:string,
  $templatePath as xs:string,
  $xqdocXhtmlPath as xs:string,
  $examplePath as xs:string) {
  let $doc := file:read-xml($templatePath)
  return block {
    insert node <title>Documentation for {xqdoc2html:module-uri($xqdoc)}</title>
    as first into $doc/*:html/*:head;

    insert nodes $menu
    as last into $doc/*:html/*:body/*:div[@id='main']/*:div[@id='leftMenu'];

    let $right_content := $doc/*:html/*:body/*:div[@id='main']/*:div[@id='rightcontent']
    return
      if ($right_content)
      then
        insert nodes xqdoc2html:body($xqdoc, $indexCollector, $schemasCollector, $xqSrcPath, $xqdocXhtmlPath)
        as last into $right_content
      else
        ();

    $doc;
  }
};

(:~
 : This function creates the XQDoc XHTML body.
 :
 : @param $xqdoc the node containing the XQDoc XML.
 : @param $indexCollector the modules names part of the left menu.
 : @param $schemasCollector the schemas imported by the modules.
 : @param $xqSrcPath the path to the xq.src folders.
 : @param $xqdocXhtmlPath location where the resulting Xhtml will be saved on disk.
 : @return The 'body' of the XHTML.
 :)
declare function xqdoc2html:body(
  $xqdoc, 
  $indexCollector,
  $schemasCollector,
  $xqSrcPath as xs:string,
  $xqdocXhtmlPath as xs:string)
{
  (: use only the functions not marked as %private :)
  let $functions := for $function in $xqdoc/xqdoc:functions/xqdoc:function 
                    where (fn:not(exists($function/@isPrivate)) or
                           (exists($function/@isPrivate) and $function/@isPrivate ne "true"))
                    return $function
  return
  (<h1>{xqdoc2html:module-uri($xqdoc)}</h1>,
    xqdoc2html:module-description($xqdoc/xqdoc:module),
    xqdoc2html:module-resources($xqSrcPath, xqdoc2html:module-uri($xqdoc), $indexCollector),
    xqdoc2html:module-dependencies($xqdoc, $indexCollector, $schemasCollector),
    xqdoc2html:module-external-specifications($xqdoc/xqdoc:module),
    xqdoc2html:module-variables($xqdoc/xqdoc:variables),
    xqdoc2html:module-function-summary($functions),
    xqdoc2html:functions($functions, $xqdocXhtmlPath)
  )
};

(:~
 : Get the XQDoc module URI.
 :
 : @param $xqdoc the node containing the XQDoc XML.
 : @return The module URI.
 :)
declare %private function xqdoc2html:module-uri($xqdoc) as xs:string
{
  $xqdoc/xqdoc:module/xqdoc:uri/text()
};

(:~
 : Return the function parameters.
 :
 : @param $comment the part of the XQDoc file holding the function parameters.
 : @return the XHTML for the function parameters.
 :)
declare function xqdoc2html:function-parameters($comment) {
  let $params := $comment/xqdoc:param
  return
    if (exists($params)) then (
      <div class="subsubsection">Parameters:</div>,
      for $param in $params
      let $text := string($param/node()[1])
      return
        if (starts-with($text, "$")) then
          let $name := substring-before($text, " ")
          let $description := (substring-after($text, " "), subsequence($param/node(), 2))
          return
            <table class="parameter"><tr>
              <td class="parameter"><code>{$name}</code></td>
              <td class="parameter"> - </td>
              <td class="parameter">{$description}</td></tr>
            </table> 
        else
            ()
    ) else ()
};

(:~
 : Return the possible function errors.
 :
 : @param $comment the part of the XQDoc file holding the function errors.
 : @return the XHTML for the function errors.
 :)
declare function xqdoc2html:errors($comment) {
  let $errors := $comment/xqdoc:error
  return
    if (exists($errors)) then (
      <div class="subsubsection">Errors</div>,
      for $error in $errors
      return
        <table class="parameter">
          <tr>
            <td class="parameter">{$error/node()}</td>
          </tr>
        </table> 
    ) else ()
};

(:~
 : This function groups together all the @see annotations.
 :
 : @param $comment the part of the XQDoc file holding the function annotations.
 : @return the XHTML for the function 'see' annotations.
 :)
declare function xqdoc2html:annotations-see($comment) {
  let $see := $comment/xqdoc:*[local-name(.) = ("see")]
  return
    if (count($see) = 0) then ()
    else
(: **********************************************************     :)
(: this hack should be replaced with links everywhere in text     :)
(: replace the @see nodes that start with http:// with HTML a tag :)
    (<div class="subsubsection">See:</div>,<ul>
    {for $annotation in $see
    return
      if(fn:count($annotation/node()) eq 1 
         and fn:starts-with(fn:lower-case($annotation/node()), "http://")) then
        <li>{<a href="{$annotation/node()}" target="_blank">{$annotation/node()}</a>}</li>
    else
        <li>{$annotation/node()}</li>}</ul>
    )
(: **********************************************************     :)
};

(:~
 : This function groups together all the @example annotations.
 :
 : @param $comment the part of the XQDoc file holding the function annotations.
 : @param $xqdocXhtmlPath location where the resulting Xhtml will be saved on disk.
 : @return the XHTML for the function 'example' annotations.
 :)
declare function xqdoc2html:annotations-example($comment, $xqdocXhtmlPath) {
  let $example := $comment/xqdoc:*[local-name(.) = ("example")]
  return
    if (count($example) = 0) then ()
    else
    (<div class="subsubsection">Examples:</div>,<ul>
    {for $annotation in $example
    return
      if(file:exists(fn:concat($xqdocXhtmlPath, file:path-separator(), "examples", file:path-separator(), 
         xqdoc2html:get-example-filename($annotation/node())))) then
        <li><a href="{fn:concat('examples',file:path-separator(), xqdoc2html:get-example-filename($annotation/node()))}" target="_blank">{xqdoc2html:get-example-filename-link($annotation/node())}</a></li>
      else
        <li>{fn:concat("The example with filename '",$annotation/node(), "' was not found.")}</li>}</ul>
    )
};

(:~
 : Create the XHTML for all function annotations except these ones:
 : <ul><li>description</li><li>param</li><li>return</li><li>error</li><li>deprecated</li><li>see</li><li>example</li></ul>.
 :
 : @param $comment the part of the XQDoc file holding the function annotations.
 : @return the XHTML for the function annotations.
 :)
declare function xqdoc2html:annotations($comment) {
  let $annotations := $comment/xqdoc:*[not((local-name(.) = ("description", "param", "return", "error", "deprecated", "see", "example")))]
  return
    for $annotation in $annotations
    let $annName := local-name($annotation)
    return 
    ( 
      <div class="subsubsection">{
        concat(upper-case(substring($annName, 1, 1)), substring($annName, 2), ":")
      }</div>,    
      <p class="annotationText">{$annotation/node()}</p>
    )
};

(:~
 : Create the XHTML for all module annotations except these ones:
 : <ul><li>description</li><li>param</li><li>return</li><li>error</li><li>deprecated</li><li>see</li><li>library</li></ul>
 :
 : @param $comment the part of the XQDoc file holding the module annotations.
 : @return the XHTML for the module annotations.
 :)
declare %private function xqdoc2html:annotations-module($comment) {
  let $annotations := $comment/xqdoc:*[not((local-name(.) = ("description", "param", "return", "error", "deprecated", "see", "library")))]
  return
    for $annotation in $annotations
    let $annName := local-name($annotation)
    return 
    ( 
      <div class="subsubsection">{
        concat(upper-case(substring($annName, 1, 1)), substring($annName, 2), ":")
      }</div>,    
      <p class="annotationText">{$annotation/node()}</p>
    )
};

(:~
 : Create the XHTML for all function return values.
 :
 : @param $comment the part of the XQDoc file holding the function annotations.
 : @return the XHTML for the function return values.
 :)
declare function xqdoc2html:function-return($comment) {
  let $return := $comment/xqdoc:return
  return
    if (exists($return)) then (
      <div class="subsubsection">Returns:</div>,
      <p class="annotationText">{$return/node()}</p>
    ) else ()
};

(:~
 : Create the XHTML for all description annotations.
 :
 : @param $comment the part of the XQDoc file holding the annotations.
 : @return the XHTML for the description annotations.
 :)
declare function xqdoc2html:description($comment) {
   <p>{if ($comment/xqdoc:description) then
         $comment/xqdoc:description/node()
       else
         "No description available."}</p>
};

(:~
 : Create the XHTML for the module resources (the implementation of the external functions).
 :
 : @param $xqSrcPath the path to the xq.src folders.
 : @param $moduleUri the module URI.
 : @param $indexCollector the modules names part of the left menu.
 : @return the XHTML for the 'Module Resources'.
 :)
declare function xqdoc2html:module-resources(
  $xqSrcPath as xs:string, 
  $moduleUri as xs:string,
  $indexCollector) {
  let $folder := xqdoc2html:get-filename($moduleUri),
      $path := concat(tokenize($xqSrcPath,fn:concat("\",file:path-separator()))[last()],
                      file:path-separator(), $folder)
  return
    (<div class="section"><span id="module_resources">Module Resources</span></div>,
     <ul>
     <li>the XQuery module can be found <a href="modules/{fn:concat($indexCollector/module[@uri=$moduleUri]/@file,".xq")}" target="_blank">here</a>.</li>
    {if(file:exists(fn:concat($xqSrcPath,file:path-separator(),$folder,file:path-separator()))) then
       <li>the implementation of the external functions can be found <a href="{$path}">here</a>.</li>
    else
      ()}
      </ul>)
};

(:~
 : Create the XHTML for the module dependencies (imported modules, schemas).
 :
 : @param $xqdoc the node containing the XQDoc XML.
 : @param $indexCollector the modules names part of the left menu.
 : @param $schemasCollector the schemas imported by the modules.
 : @return the XHTML for the 'Module Dependencies'.
 :)
declare function xqdoc2html:module-dependencies(
    $xqdoc, 
    $indexCollector, 
    $schemasCollector) {
  if (fn:count($xqdoc/xqdoc:imports/xqdoc:import) > 0 or
      fn:count($xqdoc/xqdoc:module/xqdoc:comment/xqdoc:*[(local-name(.) = ("library"))]) > 0) then
    (<div class="section"><span id="module_dependencies">Module Dependencies</span></div>,
    xqdoc2html:imports($xqdoc, $indexCollector, $schemasCollector))
  else
    ()
};

(:~
 : Create the items for the module dependencies (imported modules, schemas).
 :
 : @param $xqdoc the node containing the XQDoc XML.
 : @param $indexCollector the modules names part of the left menu.
 : @param $schemasCollector the schemas imported by the modules.
 : @return the XHTML for the 'Module Dependencies'.
 :)
declare %private function xqdoc2html:imports(
    $xqdoc, 
    $indexCollector, 
    $schemasCollector) {
  (
  if (fn:count($xqdoc/xqdoc:imports//xqdoc:import[@type = "library"]) > 0) then
    <p>Imported modules:<ul>
    {
      for $import in $xqdoc/xqdoc:imports//xqdoc:import[@type = "library"]
      return
        if (exists($indexCollector/module[@uri=$import/xqdoc:uri/text()])) then
          <li><a href="{$indexCollector/module[@uri=$import/xqdoc:uri/text()]/@file}.html">{string($import/xqdoc:uri/text())}</a></li>
        else
          <li>{string($import/xqdoc:uri/text())}</li>          
    }
    </ul></p>
  else (),
  if (fn:count($xqdoc/xqdoc:imports//xqdoc:import[@type = "schema"]) > 0) then
    <p>Imported schemas:<ul>
    {
      for $import in $xqdoc/xqdoc:imports//xqdoc:import[@type = "schema"]
      return
        if (exists($schemasCollector/module[@uri=$import/xqdoc:uri/text()])) then
          <li><a href="{$schemasCollector/module[@uri=$import/xqdoc:uri/text()]/@file}" target="_blank">{string($import/xqdoc:uri/text())}</a></li>
        else
          <li>{string($import/xqdoc:uri/text())}</li>  
    }
    </ul></p>
  else (),
  if (fn:count($xqdoc/xqdoc:module/xqdoc:comment/xqdoc:*[(local-name(.) = ("library"))]) > 0) then
    <p>External C++ library dependencies:<ul>
      {
      for $library in $xqdoc/xqdoc:module/xqdoc:comment/xqdoc:*[(local-name(.) = ("library"))]
        return
         <li>{$library/node()}</li>
      }
    </ul></p>
  else ()
  )
};

(:~
 : Create the module description and module annotations.
 :
 : @param $module the node containing the XQDoc XML module.
 : @return the XHTML for the module description and module annotations.
 :)
declare function xqdoc2html:module-description($module) {
    (<div class="section"><span id="module_description">Module Description</span></div>,
     xqdoc2html:description($module/xqdoc:comment),
     xqdoc2html:annotations-module($module/xqdoc:comment))
};

(:~
 : Create the items for the Related Specifications 
 : ('see' annotattions appearing in the module description part).
 :
 : @param $module the node containing the XQDoc XML module.
 : @return the XHTML for the 'Related Specifications'.
 :)
declare function xqdoc2html:module-external-specifications($module) {
  if(fn:count($module/xqdoc:comment/xqdoc:*[(local-name(.) = ("see"))]) >0) then
    (<div class="section"><span id="external_specifications">Related Specifications</span></div>,
    <p>For more details please check out these resources:<ul>
    {
      let $annotations := $module/xqdoc:comment/xqdoc:*[(local-name(.) = ("see"))]
      return
        for $annotation in $annotations
          return
          if(fn:count($annotation/node()) eq 1 
             and fn:starts-with(fn:lower-case($annotation/node()), "http://") ) then
            <li><a href="{$annotation/node()}" target="_blank">{$annotation/node()}</a></li>
          else
            <li>{$annotation/node()}</li>
    }
    </ul></p>)
  else
  ()
};

(:~
 : Create the module variables XHTML.
 :
 : @param $variables the node containing the XQDoc XML variables.
 : @return the XHTML for the module variables.
 :)
declare function xqdoc2html:module-variables($variables)
{
  if($variables/xqdoc:variable) then
    (<div class="section"><span id="variables">Variables</span></div>,
    <table class="varlist">
    {      
      for $variable in $variables/xqdoc:variable
      let $varName := $variable/xqdoc:uri/text()
      (:where empty($variable/xqdoc:invoked) :)
      order by $varName
      return (<tr>
              <td>{$variable/xqdoc:uri/text()}</td>
              <td>{xqdoc2html:description($variable/xqdoc:comment)}</td>
              </tr>
             )
    }</table>)
  else
    ()
};

(:~
 : Create the functions summary XHTML table.
 :
 : @param $functions the node containing the XQDoc XML functions.
 : @return the XHTML for the module function summary.
 :)
declare function xqdoc2html:module-function-summary($functions)
{
  <div class="section"><span id="function_summary">Function Summary</span></div>,
  if(count($functions)) then
    <table class="funclist">{
      for $function in $functions
      let $name := $function/xqdoc:name/text(),
          $signature := $function/xqdoc:signature/text(),
          $param-number := $function/@arity,
          $isDeprecated := fn:exists($function/xqdoc:comment/xqdoc:deprecated),
          $description := data($function/xqdoc:comment/xqdoc:description),
          $shortDescription := if(not(fn:substring-before($description,".") = "")) then
                               fn:concat(fn:substring-before($description,"."),".") else ""
      order by $name, $param-number 
      return
        let $type := normalize-space(substring-after(substring-before($signature, "function"), "declare")),
            $isExternal := ends-with($signature, "external"),    
            $paramsAndReturn := substring-after($signature,concat(':',$name)),
            $external := if(ends-with($signature,"external")) then "external" else ""
        return
          <tr>
            <td class="type">{$type}</td>
            <td>
              <tt>{
                if ($isDeprecated) then
                  <span class="functName"><del><a href="#{$name}-{$param-number}" title="{normalize-space($description)}">{$name}</a></del></span>
                else
                  <span class="functName"><a href="#{$name}-{$param-number}" title="{normalize-space($description)}">{$name}</a></span>
              }{xqdoc2html:split-function-signature($paramsAndReturn)}<br /><span class="padding">{$shortDescription}</span>
              </tt>
            </td>
            <td class="type">{$external}</td>
          </tr>
    }</table>
  else
      <p>No <a href="http://www.w3.org/TR/xquery-11/#doc-xquery11-PrivateOption">public</a> functions declared.</p>
};

(:~
 : Append in the beginning of the function name
 : updating, sequential, nondeterministic is applicable.
 :
 : @param $name the function name.
 : @param $signature the signature of the function.
 : @return a new string for the function name.
 :)
declare %private function xqdoc2html:module-function-link($name as xs:string, $signature) {

let $lcSignature := fn:lower-case($signature)
let $lname := if(ends-with($signature, 'external')) then concat($name, ' external') else $name
return
  if(contains($lcSignature, 'updating')) then
    concat('updating ',$lname)
  else if(contains($lcSignature, 'sequential')) then
    concat('sequential ',$lname)
  else if(contains($lcSignature, 'nondeterministic')) then
    concat('nondeterministic ',$lname)
  else 
    $lname
};

(:~
 : Create the details for all the functions.
 :
 : @param $functions the node containing the XQDoc XML functions.
 : @param $xqdocXhtmlPath location where the resulting Xhtml will be saved on disk.
 : @return the XHTML for the function details.
 :)
declare function xqdoc2html:functions($functions, $xqdocXhtmlPath) {
    if(count($functions)) then (
      <div class="section"><span id="functions">Functions</span></div>,
      for $function in $functions
      let $name := $function/xqdoc:name/text(),
          $signature := $function/xqdoc:signature/text(),
          $param-number := $function/@arity,
          $comment := $function/xqdoc:comment,
          $isDeprecated := fn:exists($comment/xqdoc:deprecated)
      order by $name, $param-number
      return (
        <div class="subsection" id="{$name}-{$param-number}">{
          if ($isDeprecated) then
            <del>{xqdoc2html:module-function-link($name, $signature)}</del>
          else
            xqdoc2html:module-function-link($name, $signature)
        }</div>,
        if ($isDeprecated) then
          <p><span class="deprecated">Deprecated</span>{
            if (exists($comment/xqdoc:deprecated/node())) then
              (" - ", $comment/xqdoc:deprecated/node())
            else
              ()
          }</p>
        else
          (),
        <pre class="signature">{xqdoc2html:split-function-signature($signature)}</pre>,
        xqdoc2html:description($comment),
        xqdoc2html:function-parameters($comment),
        xqdoc2html:function-return($comment),
        xqdoc2html:errors($comment),
        xqdoc2html:annotations($comment),
        xqdoc2html:annotations-see($comment),
        xqdoc2html:annotations-example($comment, $xqdocXhtmlPath),
        <div id="allignright"><a href="#function_summary" title="Back to 'Function Summary'">'Function Summary'</a></div>,  
        <hr />)                
       )
    else ()
};

(:~
 : Pretty print the function signature.
 :
 : @param $signature the function signature.
 : @return the XHTML for the function signature after reformatting was done.
 :)
declare function xqdoc2html:split-function-signature($signature as xs:string) {
  let $line1 := substring-before($signature, "(")
  let $rest := substring-after($signature, "(")
  let $params :=
    (: if the function has parameter :)
    if (matches($rest, "\$")) then
      let $tmp := substring-before($rest, ") as ")
      return 
        (: if we don't have a return type specified :)
        if ($tmp eq "") then
          (: en external function declaration :)
          if (ends-with($rest, ") external")) then
            substring-before($rest, ") external")
          (: no external function :)
          else
            $rest
        (: the return type is specified :)
        else
          $tmp
    (: no parameters :)
    else
      ""
  let $after := substring-after($signature, concat($params, ")"))
  let $parts := fn:tokenize($line1,' ')
  let $line11 := fn:string-join(for $part in $parts return if(fn:contains($part,":")) then () else $part, ' ')
  let $line12 := fn:substring-after($line1, normalize-space($line11))
  return (
    $line11,<span class="functName">{$line12}</span>," (&#0010;",
    for $param at $pos in tokenize($params, "\$")
    let $nsParam := normalize-space($param)
    let $param1 := if(contains($nsParam,"as")) then fn:substring-before($nsParam," as ")
                   else if(contains($nsParam,",")) then fn:substring-before($nsParam,",")
                   else if(contains($nsParam,")")) then fn:substring-before($nsParam,")")
                   else $nsParam
    let $param2 := fn:substring-after($nsParam, $param1)
    where $pos > 1
    return (
      <span class="funcParam">{concat("            $", $param1)}</span>,$param2,"&#0010;"),
    concat(")", $after)
  )
};
