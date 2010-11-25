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
module namespace xqdoc2html = "http://www.zorba-xquery.com/modules/xqdoc2xhtml";

import module namespace file = "http://www.zorba-xquery.com/modules/file";
import module namespace xqd = "http://www.zorba-xquery.com/modules/xqdoc";

import schema namespace xqdoc = "http://www.xqdoc.org/1.0";

declare copy-namespaces preserve, inherit;

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
  </links>;

(:~
 : This is the name of the function index XHTML page.
 :)
declare variable $xqdoc2html:functionIndexPageName as xs:string := "function_index.html";

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
    ""
  else
    for $file in file:files($folderPath, $pattern, fn:true())
    let $filePath := fn:concat($folderPath, file:path-separator(), $file)
    let $remove := file:remove($filePath) 
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
 : @param   $pattern where to generate the XQDoc XML documents.
 : @return  Empty sequence.
 :)
declare %private sequential function xqdoc2html:gather-and-copy(
  $sourcePath       as xs:string,
  $destinationPath  as xs:string, 
  $pattern          as xs:string)
{
  if(fn:not(file:exists($destinationPath))) then
    ""
  else
    for $file in file:files($sourcePath, $pattern, fn:true())
    let $fileName := fn:tokenize($file, file:path-separator())[last()]
    let $fileSourcePath := fn:concat($sourcePath, file:path-separator(), $file)
    let $fileDestinationPath := fn:concat($destinationPath, file:path-separator(), $fileName)
    return
      file:copy($fileSourcePath, $fileDestinationPath, fn:false())
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
  if(file:mkdirs($destinationPath, false())) then
  (
    let $clear := xqdoc2html:clear-folder($destinationPath, $pattern)
    let $clear := xqdoc2html:gather-and-copy($sourcePath, $destinationPath, $pattern)
      return ()
  )
  else
    error()
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
  if (file:mkdirs($xqSrcPath, false())) then
  (
    xqdoc2html:clear-folder($xqSrcPath,"(\.cpp|\.h)$"),
    
    (: gather all .xq.src folders :)
    let $xqSrcFolders :=  fn:distinct-values(
                            for $file in file:files($modulePath, "(\.cpp|\.h)$", fn:true())
                            where ends-with(fn:tokenize($file, file:path-separator())[last()-1],'xq.src')
                            return
                              substring-before($file,'.xq.src'))
    
    (: 
      create the needed folders in $xqSrcPath and copy all the .cpp and .h into them
      the folder name is the same as the name of the .xml file (without the .xml extension) for that module
    :)
    for $xqSrcFolder in $xqSrcFolders
    let $xqSrcSourcePath := fn:concat($modulePath, file:path-separator(), $xqSrcFolder, '.xq.src')
    let $xqSrcDestinationPath := fn:concat($xqSrcPath, file:path-separator(),
                                 xqdoc2html:get-filename(xqdoc2html:get-URI-from-location($xqSrcFolder)))
    return
      xqdoc2html:copy-files($xqSrcSourcePath, $xqSrcDestinationPath, "(\.cpp|\.h)$")
  )
  else
    error()
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
    $imagesPath     := fn:concat($xhtmlPath,      file:path-separator(), "images"),
    $libPath        := fn:concat($xhtmlPath,      file:path-separator(), "lib"),
    $cssPath        := fn:concat($xhtmlPath,      file:path-separator(), "css"),
    $templatesPath  := fn:concat($xhtmlPath,      file:path-separator(), "templates"),
    $examplesPath   := fn:concat($xhtmlPath,      file:path-separator(), "examples")
return
  (: first - create the xhtml folder is it does not exist already :)
  if (file:mkdirs($xhtmlPath, false())) then
  (
    (: second - clear the folder of all the files with these extensions :)
    xqdoc2html:clear-folder($xhtmlPath,"(\.xsd|\.gif|\.js|\.css|\.html|\.cpp|\.h|\.xq)$"),

    (: third - re-copy these files :)
    xqdoc2html:copy-files($modulesPath, $schemasPath, "\.xsd$"),
    xqdoc2html:copy-files($xhtmlRequisitesPath, $imagesPath, "\.gif$"),
    xqdoc2html:copy-files($xhtmlRequisitesPath, $libPath, "\.js$"),
    xqdoc2html:copy-files($xhtmlRequisitesPath, $cssPath, "\.css$"),
    xqdoc2html:copy-files($xhtmlRequisitesPath, $templatesPath, "\.html$"),

    xqdoc2html:copy-xqsrc-folders($modulesPath, $xqSrcPath),

    (: only create the examples folder. The examples will be copied later on in the process :)
    file:mkdirs($examplesPath, false())
  )
  else
    error()
};

(:~ Returns the URI of the module given the passed $folderPath using the Zorba URI resolving mechanism.
 :
 : @param $folderPath the folder path.
 : @return the URI of the module.
 :
 :)
declare %private function xqdoc2html:get-URI-from-location($folderPath as xs:string) as xs:string {
  let $tok := tokenize($folderPath, file:path-separator())
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
    replace(
        replace($moduleURI, "/", "_"),
        "http:__",
        ""
    )
};

(:~
 : This function generates the XQDoc XML for all the modules found in $modulesPath
 : and writes the resulting XML documents in $targetPath. The hierarchy is not preserved.
 :
 : @param $modulePath where to search for modules recursively.
 : @param $xqdocXmlPath where to generate the XQDoc XML documents.
 : @param $examplePath string with the paths where the examples are kept separated by ; .
 : @return A string sequence with a status message for each processed module.
 :)
declare sequential function xqdoc2html:generate-xqdoc-xml(
  $modulesPath as xs:string, 
  $xqdocXmlPath as xs:string,
  $examplePath as xs:string) as xs:string* {
  for $filedirs in tokenize($modulesPath, ";")
  for $file in file:files($filedirs, "\.xq$", fn:true())
  let $filePath := fn:concat($filedirs, file:path-separator(), $file)
  let $xqdoc := xqd:xqdoc(file:path-to-uri($filePath))
  let $xqdoc := xqdoc2html:configure-xml($xqdoc, $examplePath)
  let $moduleDoc := $xqdoc/xqdoc:module
  let $moduleName := $moduleDoc/xqdoc:name
  let $moduleUri := $moduleDoc/xqdoc:uri
  return
    try {
      file:mkdirs($xqdocXmlPath, false());
      let $x := fn:count(file:files($xqdocXmlPath, "\.xml$", fn:true())) + 1
      let $xqdocFileName := fn:concat($xqdocXmlPath, file:path-separator(), xqdoc2html:get-filename($moduleUri), ".xml")
      return          
      file:write($xqdocFileName, $xqdoc, <s method="xml" indent="yes" />/@*);
      concat("
SUCCESS: ", $moduleUri, " (", ()(:$xqdocFileName:), ")");
    } catch * ($error_code) {
      concat("
FAILED: ", $moduleUri, " (", ()(:$xqdocFileName:), ")")
    }
};


(:~
 : This function generates the XQDoc XHTML pages for all the XQDoc XML
 : documents found in $xqdocPath and writes the resulting pages to $targetPath. 
 : The hierarchy is not preserved. 
 :
 : @param $indexPath path to the XHTML index page.
 : @param $xqdocXmlPath path to the XQDoc XML files.
 : @param $xqdocXhtmlPath location where the resulting Xhtml will be saved on disk.
 : @param $xqSrcPath location of the xq.src folder containing the implementation of the external functions.
 : @param $leftMenu the menu containing the links to the generated Xhtml files.
 : @param $modulesPath the path to the .xq modules.
 : @param $functionIndexPageName the name of the generated page for the function index.
 : @return a string sequence with the status of every processed XQDoc XML file.
 :)
declare %private sequential function xqdoc2html:generate-xqdoc-xhtml(
  $indexPath              as xs:string, 
  $xqdocXmlPath           as xs:string,
  $xqdocXhtmlPath         as xs:string, 
  $xqSrcPath              as xs:string,
  $leftMenu               as element(menu),
  $modulesPath            as xs:string, 
  $functionIndexPageName  as xs:string) as xs:string* {
  let $indexHtmlDoc := file:read-xml($indexPath)
  return
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
      let $menu := <ul id="documentation">
      <span><a href="index.html">{string($leftMenu/@title)}</a></span>
      <li><a href="{$functionIndexPageName}">Function Index</a></li>
      {
        for $link in $xqdoc2html:externalLinks//a
        return
          <li>{$link}</li>
      }      
      </ul>
      let $menu := xqdoc2html:create-module-table($leftMenu, $menu, $moduleUri)
      let $xhtml := xqdoc2html:doc($xqdoc, $menu, $xqdoc2html:indexCollector, $xqdoc2html:schemasCollector, $xqSrcPath)
      return block {
        file:mkdirs($xhtmlFileDir, false());

        xqdoc2html:configure-xhtml($xhtml, $modulesPath);

        file:write($xhtmlFilePath, $xhtml, <s method="xhtml" indent="yes" />/@*);

        concat("
SUCCESS: ", $moduleUri, " (", $xhtmlFilePath, ")");
      }
    } catch * ($error_code) {
      concat("
FAILED: ", $xhtmlFilePath)
    }
};

(:~
 : This function generates the XQDoc function index page and writes it to disk.
 : @param $indexFunctionLeft the menu containing the links to the generated Xhtml files.
 : @param $xqdocXhtmlPath location where the resulting XQDoc function index page will be saved.
 : @param $indexPageName the name of the resulting XQDoc function index page.
 : @return a string indicationg if the function index page was created successfully.
 :)
declare sequential function xqdoc2html:generate-function-index-xhtml(
  $indexFunctionLeft,
  $xqdocXhtmlPath as xs:string,
  $indexPageName as xs:string
) as xs:string* {
let $content :=<html>
  <head>
    <title>Indexed Library Module Functions</title>
    <meta content="text/html; charset=UTF-8" http-equiv="content-type" />
    <meta content="PRIVATE" http-equiv="CACHE-CONTROL" />
    <meta content="-1" http-equiv="Expires" />
    <link rel="stylesheet" type="text/css" href="css/main.css" />
    <link rel="stylesheet" href="css/jquery.treeview.css" />
    <link rel="stylesheet" href="css/screen.css" />
    <script src="lib/jquery.js" type="text/javascript"> </script>
    <script src="lib/jquery.cookie.js" type="text/javascript"> </script>
    <script src="lib/jquery.treeview.js" type="text/javascript"> </script>
    <script type="text/javascript">
      $(function() &#123;
        $("#documentation").treeview(&#123;
            animated: "fast",
            collapsed: true,
            unique: false,
            persist: "cookie"
        &#125;);
      &#125;)
    </script>
  </head>
  <body>
  <div id="main">
    <div id="leftMenu">
    {$indexFunctionLeft}
    </div>
    <div id="rightcontent">
    <div class="section">
            <span id="module_description">Indexed Library Module Functions</span>
    </div>
    {xqdoc2html:generate-function-index()}
    </div>
  </div>
  </body>
</html>
return
  try {
    file:write(fn:concat($xqdocXhtmlPath, file:path-separator(), $indexPageName), $content, <s method="xhtml" indent="yes" />/@*);
  } catch * ($error_code) {
      concat("
FAILED: ", fn:concat($xqdocXhtmlPath, file:path-separator()))
  }  
};

(:~
 : This function gathers schemas found in the $xqdocSchemasPath and fills the $xqdoc2html:schemasCollector.
 : @param $xqdocSchemasPath the path where the schemas are stored.
 : @return a string sequence indicationg the result of every processed schema.
 :)
declare %private sequential function xqdoc2html:gather-schemas(
  $xqdocSchemasPath as xs:string) as xs:string* {
  
  for $filedirs in $xqdocSchemasPath
  for $file in file:files($filedirs, "\.xsd$", fn:false())
  let $xsdFilePath := concat($xqdocSchemasPath, file:path-separator(), $file)
  let $xqdRelFilePath := concat(tokenize($xqdocSchemasPath,file:path-separator())[last()],
                                file:path-separator(), $file)
  return
    try {
      let $xqdoc := file:read-xml($xsdFilePath)
      let $xsdUri := $xqdoc/xs:schema/@targetNamespace
      return block {
          xqdoc2html:collect-module($xsdUri, $xqdRelFilePath, $xqdoc2html:schemasCollector);
          concat("
  SUCCESS: ", $xsdUri, " (", $xsdFilePath, ")");
        }
      } catch * ($error_code) {
        concat("
  FAILED: ", $xsdFilePath)
      }  
};

(:~
 : This function gathers the modules found in the $xqdocXmlPath and fills the $xqdoc2html:indexCollector.
 : @param $xqdocXmlPath the path where the XQDoc XML modules are stored.
 : @return a string sequence indicationg the result of every processed XQDoc XML file.
 :)
declare %private sequential function xqdoc2html:gather-modules(
  $xqdocXmlPath as xs:string
){
  for $file in file:files($xqdocXmlPath, "\.xml$", fn:true())
  let $xmlFilePath := concat($xqdocXmlPath, file:path-separator(), $file)
  let $xhtmlRelativeFilePath := fn:replace($file, "\.xml$", ".html")
  let $xhtmlRelativeFilePathSlash := fn:replace($xhtmlRelativeFilePath, fn:concat("\", file:path-separator()), "/")
  return
  try {
      let $xqdoc := file:read-xml($xmlFilePath)/xqdoc:xqdoc
      let $moduleDoc := $xqdoc/xqdoc:module
      let $moduleUri := $moduleDoc/xqdoc:uri
      return if($moduleDoc/@type = "library") then 
        block {
          xqdoc2html:collect-module($moduleUri/text(), $xhtmlRelativeFilePath, $xqdoc2html:indexCollector);
          
          xqdoc2html:collect-functions($xqdoc, $xhtmlRelativeFilePath, $xqdoc2html:functionsCollector);
          concat("
SUCCESS: ", $moduleUri, " (", $xmlFilePath, ")");
        }
       else concat("
Ignore main module: ", $xmlFilePath) 
    } catch * ($error_code) {
      concat("
FAILED: ", $xmlFilePath)
    }  
};

(:~
 : This function adds a new record into the $collector.
 : @param $moduleDoc the module URI.
 : @param $relativeFileName the relative path to the module.
 : @param $collector the name of the collector.
 : @return empty sequence.
 :)
declare %private sequential function xqdoc2html:collect-module (
  $moduleDoc as xs:string, 
  $relativeFileName as xs:string, 
  $collector) 
{
  insert node <module uri="{$moduleDoc}" file="{$relativeFileName}" /> as last into $collector;
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
declare %private sequential function xqdoc2html:get-file-path (
  $filename as xs:string,
  $examplePath as xs:string
) as xs:string* {
  let $paths := tokenize($examplePath,';')
  for $path in $paths
  let $test := file:files($path,concat("^",$filename,"$"),fn:true())[1]
  return
    if (fn:exists($test)) then
      fn:concat($path,file:path-separator(),$test)
    else 
      ()
};

(:~
 : This function does some additional processing for the $xml like
 : replacing examples with actual links to files.
 : @param $xml the node containing the XHTML file.
 : @param $examplePath string with the paths where the examples are kept separated by ; .
 : @return the processed $xhtml.
 :)
declare %private sequential function xqdoc2html:configure-xml (
  $xml,
  $examplePath as xs:string ) {
    
  (: copy the example into the 'examples' folder :)

  (: replace the file name with a link to the actual file (stored in 'examples' folder) in the xml :)

  (: replace the @inlineExamples with actual inline code :)

  $xml;
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
      $xq11Spec := "http://www.w3.org/TR/xquery-11/#FunctionDeclns"
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
    else ();
  };
  
  (: replace the function names description with images+name of the functions :) 
  let $xquSpec := "http://www.w3.org/TR/xquery-update-10/",
      $xqsSpec := "http://www.w3.org/TR/xquery-sx-10/#dt-sequential-function",
      $xq11Spec := "http://www.w3.org/TR/xquery-11/#FunctionDeclns"
  let $imagesPath := "images/"
  for $func in $xhtml//*:div
  where $func/@class eq "subsection"
  let $funcName := $func/text()
  return block {
    if (starts-with($funcName, "updating")) then
      replace node $func/text() with
        (<a href="{$xquSpec}" title="updating" target="_blank"><img src="{concat($imagesPath, "U.gif")}" /></a>,
        text {substring-after($funcName, "updating")})
        
    else if (starts-with($funcName, "sequential")) then
      replace node $func/text() with
        (<a href="{$xqsSpec}" title="sequential" target="_blank"><img src="{concat($imagesPath, "S.gif")}" /></a>,
        text {substring-after($funcName, "sequential")})
        
    else if (starts-with($funcName, "nondeterministic")) then
      replace node $func/text() with
        (<a href="{$xq11Spec}" title="nondeterministic" target="_blank"><img src="{concat($imagesPath, "N.gif")}" /></a>,
        text {substring-after($funcName, "nondeterministic")})
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
 : This function creates menu header for the index.html or function index XHTML pages.
 :
 : @param $leftMenu the menu.
 : @param $isFunctionIndex true for the function index XHTML page, false for the index.html.
 : @param $functionIndexPageName the name of the function index XHTML page.
 : @return $root after the subcategories were added to it.
 :)
declare %private function xqdoc2html:create-left-menu(
  $leftMenu as element(menu), 
  $isFunctionIndex as xs:boolean, 
  $functionIndexPageName as xs:string) {
  <ul id="documentation">    
    {
    (
      if($isFunctionIndex) then
        (
        <span><a href="index.html">{string($leftMenu/@title)}</a></span>,    
        <li><span class="leftmenu_active">Function Index</span></li>)
      else
        (<span class="leftmenu_active">{string($leftMenu/@title)}</span>,
        
      <li><a href="{$functionIndexPageName}">Function Index</a></li>),      
      
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
      order by fn:data($module/@uri)
      return
        if(fn:starts-with(fn:string($module/@uri),data($category/@uri))
           and fn:not(fn:contains (fn:substring-after(data($module/@uri),fn:concat(data($category/@uri),'/')),'/'))) then
        (
          let $uri := if(fn:substring-after(data($module/@uri),fn:concat(data($category/@uri),'/')) = "") then
                        fn:substring-before($module/@file,".html")
                      else
                        fn:substring-after(data($module/@uri),fn:concat(data($category/@uri),'/'))
          
          return
            if(fn:string($module/@uri) = $moduleUri) then
              <li><span class="leftmenu_active">{$uri}</span></li>
            else 
              <li><a href="{$module/@file}">{$uri}</a></li>
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
 : @param $indexPath Where to search for XML XQDoc documents recursively.
 : @param $menu the menu.
 : @param $modules the modules.
 : @return The content of the new index.html.
 :)
declare %private sequential function xqdoc2html:generateIndexHtml(
  $indexPath as xs:string, 
  $menu, 
  $modules) as document-node() {
    let $indexHtmlDoc := file:read-xml($indexPath)
    return block {
        insert nodes $menu
        as last into $indexHtmlDoc/*:html/*:body/*:div[@id='main']/*:div[@id='leftMenu'];

        let $module_list := $indexHtmlDoc/*:html/*:body/*:div[@id='main']/*:div[@id='rightcontent']/*:div[@id='module_list']
        return
          if ($module_list)
          then
            insert node $modules as last into $module_list
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
 : @return Empty sequence.
 :)
declare sequential function xqdoc2html:main(
  $modulePath as xs:string, 
  $xqdocBuildPath as xs:string,
  $xhtmlRequisitesPath as xs:string,
  $examplePath as xs:string
) {
    let $leftMenu :=
    <menu title="XQuery Modules Documentation">
    <category name="http://expath.org/ns" uri="http://expath.org/ns" />
    <category name="http://www.zorba-xquery.com/modules" uri="http://www.zorba-xquery.com/modules" >
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
    </category>
    <category name="http://www.w3.org/2005" uri="http://www.w3.org/2005" />
    <category name="www.functx.com" uri="http://www.functx.com" />
    </menu>
    let $indexHtmlPath as xs:string := fn:concat($xhtmlRequisitesPath, file:path-separator(), "templates", file:path-separator(), "index.html")
    return xqdoc2html:main($leftMenu, $modulePath, $xqdocBuildPath, $indexHtmlPath, $examplePath)
};

(:~
 : This function creates the XQDoc XMLs and from them the XQDoc XHTMLs.
 :
 : @param $leftMenu the menu containing the links to the generated XHTMLs.
 : @param $modulePath where to search for .xq modules recursively.
 : @param $xqdocBuildPath where to output the XQDoc XMLs and XHTMLs.
 : @param $indexHtmlPath where to load the template for the index.html.
 : @param $examplePath string with the paths where the examples are kept separated by ; .
 : @return Empty sequence.
 :)
declare %private sequential function xqdoc2html:main(
  $leftMenu as element(menu),
  $modulePath as xs:string, 
  $xqdocBuildPath as xs:string,
  $indexHtmlPath as xs:string,
  $examplePath as xs:string
) {  
  declare $xqdocXmlPath   as xs:string := fn:concat($xqdocBuildPath, file:path-separator(), "xml");
  declare $xqdocXhtmlPath as xs:string := fn:concat($xqdocBuildPath, file:path-separator(), "xhtml");
  declare $xqdocSchemasPath as xs:string := fn:concat($xqdocXhtmlPath, file:path-separator(), "schemas");
  declare $xqSrcPath as xs:string := fn:concat($xqdocXhtmlPath, file:path-separator(), "xq.src");
  
  (: generate the XQDoc XML for all the modules :)
  if (file:mkdirs($xqdocXmlPath, false())) then
  (
    xqdoc2html:clear-folder($xqdocXmlPath,"\.xml$"),
    xqdoc2html:generate-xqdoc-xml($modulePath, $xqdocXmlPath, $examplePath)
  )
  else
    error()
  ;
  
    
  (: generate the XQDoc XHTML for all the modules :) 
  let $absoluteXhtmlDir := concat($xqdocBuildPath, "/xhtml")
  return
  if (file:mkdirs($absoluteXhtmlDir, false())) then
  (
    xqdoc2html:clear-folder($xqdocXhtmlPath,"xqdoc\.html$"),
    xqdoc2html:gather-modules($xqdocXmlPath),
    xqdoc2html:gather-schemas($xqdocSchemasPath),    
    xqdoc2html:generate-xqdoc-xhtml($indexHtmlPath, $xqdocXmlPath, $xqdocXhtmlPath, $xqSrcPath, $leftMenu, $modulePath, $xqdoc2html:functionIndexPageName),
    (
      (: generate the left menu for the Function Index XHTML :)
      let $leftFunction := xqdoc2html:create-left-menu($leftMenu, fn:true(), $xqdoc2html:functionIndexPageName)
      let $indexFunctionLeft := xqdoc2html:create-module-table($leftMenu, $leftFunction, $xqdoc2html:functionIndexPageName)
      return
        xqdoc2html:generate-function-index-xhtml($indexFunctionLeft,$xqdocXhtmlPath,$xqdoc2html:functionIndexPageName)
    )
  )
  else
    error()
  ;  
  
  let $left := xqdoc2html:create-left-menu($leftMenu, fn:false(), $xqdoc2html:functionIndexPageName)
  let $indexLeft := xqdoc2html:create-module-table($leftMenu, $left, "index.html")
  let $right := <ul />
  let $indexRight := xqdoc2html:create-module-table($leftMenu, $right, "index.html")
  let $doc := xqdoc2html:generateIndexHtml($indexHtmlPath, $indexLeft, $indexRight)
  let $index := xqdoc2html:configure-xhtml($doc/*:html, $modulePath) 
  return
    file:write(fn:concat($xqdocXhtmlPath, file:path-separator(), "index.html"), $index, <s method="xhtml" indent="yes" />/@*)
  ;
 
};

(: ******************  Functions that create the content of the XHTML pages  ************************:)

(:~
 : This function creates the XQDoc XHTML.
 :
 : @param $xqdoc the node containing the XQDoc XML.
 : @param $menu the menu.
 : @param $indexCollector the modules names part of the left menu.
 : @param $schemasCollector the schemas imported by the modules.
 : @param $xqSrcPath the path to the xq.src folders.
 : @return The created XHTML page.
 :)
declare function xqdoc2html:doc(
  $xqdoc, 
  $menu, 
  $indexCollector, 
  $schemasCollector, 
  $xqSrcPath as xs:string)
{
<html>
  <head>
    <title>Documentation for {xqdoc2html:module-uri($xqdoc)}</title>
    <meta content="text/html; charset=UTF-8" http-equiv="content-type" />
    <meta content="PRIVATE" http-equiv="CACHE-CONTROL" />
    <meta content="-1" http-equiv="Expires" />
    <link rel="stylesheet" type="text/css" href="css/main.css" />
    <link rel="stylesheet" href="css/jquery.treeview.css" />
    <link rel="stylesheet" href="css/screen.css" />
    <script src="lib/jquery.js" type="text/javascript"> </script>
    <script src="lib/jquery.cookie.js" type="text/javascript"> </script>
    <script src="lib/jquery.treeview.js" type="text/javascript"> </script>
    <script type="text/javascript">
      $(function() &#123;
        $("#documentation").treeview(&#123;
            animated: "fast",
            collapsed: true,
            unique: false,
            persist: "cookie"
        &#125;);
      &#125;)
    </script>
  </head>
  <body>
  <div id="main">
    <div id="leftMenu">
    {$menu}
    </div>
    <div id="rightcontent">{xqdoc2html:body($xqdoc, $indexCollector, $schemasCollector, $xqSrcPath)}
    </div>
  </div>
  </body>
</html>
};

(:~
 : This function creates the XQDoc XHTML header.
 :
 : @param $xqdoc the node containing the XQDoc XML.
 : @return The 'head' of the XHTML.
 :)
declare function xqdoc2html:header($xqdoc)
{
  <head>
    <title>Documentation for {xqdoc2html:module-uri($xqdoc)}</title>
    <link rel="stylesheet" type="text/css" href="" />
  </head>
};

(:~
 : This function creates the XQDoc XHTML body.
 :
 : @param $xqdoc the node containing the XQDoc XML.
 : @param $indexCollector the modules names part of the left menu.
 : @param $schemasCollector the schemas imported by the modules.
 : @param $xqSrcPath the path to the xq.src folders.
 : @return The 'body' of the XHTML.
 :)
declare function xqdoc2html:body(
  $xqdoc, 
  $indexCollector, 
  $schemasCollector, 
  $xqSrcPath as xs:string)
{
  <body>
    <h1>{xqdoc2html:module-uri($xqdoc)}</h1>
    {            
      xqdoc2html:module-description($xqdoc/xqdoc:module),
      xqdoc2html:module-resources($xqSrcPath, xqdoc2html:module-uri($xqdoc), $xqdoc/xqdoc:functions),
      xqdoc2html:module-dependencies($xqdoc, $indexCollector, $schemasCollector),
      xqdoc2html:module-external-specifications($xqdoc/xqdoc:module),
      xqdoc2html:module-variables($xqdoc/xqdoc:variables),
      xqdoc2html:module-function-summary($xqdoc/xqdoc:functions),
      xqdoc2html:functions($xqdoc/xqdoc:functions)
    }
  </body>
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
 : This function groups together all the @see annotations
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
 : This function groups together all the @example annotations
 :
 : @param $comment the part of the XQDoc file holding the function annotations.
 : @return the XHTML for the function 'example' annotations.
 :)
declare function xqdoc2html:annotations-example($comment) {
  let $example := $comment/xqdoc:*[local-name(.) = ("example")]
  return
    if (count($example) = 0) then ()
    else
    (<div class="subsubsection">Examples:</div>,<ul>
    {for $annotation in $example
    return
        <li>{$annotation/node()}</li>}</ul>
    )
};

(:~
 : Create the XHTML for all function annotations except these ones:
 : <ul><li>description</li><li>param</li><li>return</li><li>error</li><li>deprecated</li><li>see</li><li>example</li></ul>
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
   <p>{
    if ($comment/xqdoc:description) then
        $comment/xqdoc:description/node()
    else
        "No description available."
   }</p>
};

(:~
 : Create the XHTML for the module resources (the implementation of the external functions).
 :
 : @param $xqSrcPath the path to the xq.src folders.
 : @param $moduleUri the module URI.
 : @param $functions the node containing the XQDoc XML functions.
 : @return the XHTML for the 'Module Resources'.
 :)
declare function xqdoc2html:module-resources(
  $xqSrcPath as xs:string, 
  $moduleUri as xs:string,
  $functions) {
  let $folder := xqdoc2html:get-filename($moduleUri),
      $path := concat(tokenize($xqSrcPath,file:path-separator())[last()],
                      file:path-separator(), $folder)
  return
    if(file:exists(fn:concat($xqSrcPath,file:path-separator(),$folder,file:path-separator()))) then
      (<div class="section"><span id="module_resources">Module Resources</span></div>,
       <ul>
       <li>The implementation of the external functions can be found <a href="{$path}">here</a>.</li>
       </ul>)
    else
      ()
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
          <li><a href="{$indexCollector/module[@uri=$import/xqdoc:uri/text()]/@file}">{string($import/xqdoc:uri/text())}</a></li>
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
 : Create the items for the external specifications 
 : ('see' annotattions appearing in the module description part).
 :
 : @param $module the node containing the XQDoc XML module.
 : @return the XHTML for the 'External Specifications'.
 :)
declare function xqdoc2html:module-external-specifications($module) {
  if(fn:count($module/xqdoc:comment/xqdoc:*[(local-name(.) = ("see"))]) >0) then
    (<div class="section"><span id="external_specifications">External Specifications</span></div>,
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
  if(count($functions/xqdoc:function)) then
    <table class="funclist">{
      for $function in $functions/xqdoc:function
      let $name := $function/xqdoc:name/text(),
        $signature := $function/xqdoc:signature/text(),
        $param-number := $function/@arity,
        $isDeprecated := fn:exists($function/xqdoc:comment/xqdoc:deprecated)
      order by $name, $param-number 
      return
        let $type := normalize-space(substring-after(substring-before($signature, "function"), "declare")),
            $isExternal := ends-with($signature, "external"),    
            $paramsAndReturn :=
              let $searchCrit := concat(":", $name)
              return
                if ($isExternal)
                  then normalize-space(substring-before(substring-after($signature, $searchCrit), "external"))
                  else normalize-space(substring-after($signature, $searchCrit))
        return
          <tr>
            <td class="type">{$type}</td>
            <td>
              <tt>{
                if ($isDeprecated) then
                  <del><a href="#{$name}-{$param-number}">{$name}</a></del>
                else
                  <a href="#{$name}-{$param-number}">{$name}</a>
              }{$paramsAndReturn}</tt>
            </td>
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
return
  if(contains($lcSignature, 'updating')) then
    concat('updating ',$name)
  else if(contains($lcSignature, 'sequential')) then
    concat('sequential ',$name)
  else if(contains($lcSignature, 'nondeterministic')) then
    concat('nondeterministic ',$name)
  else 
    $name
};

(:~
 : Create the details for all the functions.
 :
 : @param $functions the node containing the XQDoc XML functions.
 : @return the XHTML for the function details.
 :)
declare function xqdoc2html:functions($functions) {
    if(count($functions/xqdoc:function)) then (
      <div class="section"><span id="functions">Functions</span></div>,
      for $function in $functions/xqdoc:function
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
        xqdoc2html:annotations-example($comment),
        <div id="allignright"><a href="#function_summary" title="Back to 'Function Summary'">'Function Summary'</a></div>,  
        <hr />)                
       )
    else ()
};

(:~
 : Pretty print the function signature.
 :
 : @param $signature the function signature.
 : @return the XHTML for the function signature after reformating was done.
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
  return (
    concat($line1, " ("),
    <br />,
    for $param at $pos in tokenize($params, "\$")
    where $pos > 1
    return (
      concat("            $", normalize-space($param)),
      <br/>                    
    ),
    concat(")", $after)
  )
};

