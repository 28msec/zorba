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
 : @project xqdoc/xqdoc2xhtml
 :)
module namespace xqdoc2html  = "http://www.zorba-xquery.com/modules/xqdoc2xhtml/";

import module namespace xqd  = "http://www.zorba-xquery.com/modules/xqdoc";
import module namespace err  = "http://www.zorba-xquery.com/modules/xqdoc2xhtml/error";

import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";

import module namespace pxqdoc = "http://www.zorba-xquery.com/modules/project_xqdoc";

import module namespace file = "http://expath.org/ns/file";

import schema namespace xqdoc = "http://www.xqdoc.org/1.0";
import schema namespace output = "http://www.w3.org/2010/xslt-xquery-serialization";

declare copy-namespaces preserve, inherit;

declare variable $xqdoc2html:xqFolderName as xs:string := "external_functions_impl";
declare variable $xqdoc2html:moduleFolderName as xs:string := "modules";
declare variable $xqdoc2html:exampleFolderName as xs:string := "examples";

declare variable $xqdoc2html:collection as xs:QName := xs:QName("xqdoc2html:collection");
declare collection xqdoc2html:collection as node()*;

declare variable $xqdoc2html:collectionConfig as xs:QName := xs:QName("xqdoc2html:collectionConfig");
declare collection xqdoc2html:collectionConfig as node()*;

declare variable $xqdoc2html:menuEntries := <entries/>;

(:~
 : This variable contains all the schemas imported by the modules
 :)
declare variable $xqdoc2html:schemasCollector := <schemas/>;

(:~
 : The serialization parameters for XML serialization.
 :)
declare variable $xqdoc2html:serParamXml :=
  <output:serialization-parameters>
    <output:method value="xml"/>
    <output:indent value="yes"/>
  </output:serialization-parameters>;
(:~
 : The serialization parameters for XHTML serialization.
 :)
declare variable $xqdoc2html:serParamXhtml:=
  <output:serialization-parameters>
    <output:method value="xhtml"/>
    <output:indent value="yes"/>
  </output:serialization-parameters>;
(:~
 : The serialization parameters for text serialization.
 :)
declare variable $xqdoc2html:serParamText :=
  <output:serialization-parameters>
    <output:method value="text"/>
  </output:serialization-parameters>;

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
    <a href="images/modules.svg" 
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
(:_____________________________________________________________________________________________________:)

(:~
 : This function adds a new record into the $collector.
 : @param $moduleURI the module URI.
 : @param $relativeFileName the relative path to the module.
 : @param $collector the name of the collector.
 : @param $containsExternalFuncs true is the module contails external functions.
 : @return empty sequence.
 :)
declare %private %sequential function xqdoc2html:collect-module (
  $moduleURI as xs:string, 
  $relativeFileName as xs:string, 
  $containsExternalFuncs as xs:boolean,
  $collector) 
{
  insert node <module uri="{$moduleURI}" file="{$relativeFileName}" pureXQuery="{not($containsExternalFuncs)}"/> as last into $collector;
};

(:~
 : This function adds a new record into the $collector.
 : @param $schemaURI the schema URI.
 : @param $fileName the schema file name.
 : @param $collector the name of the collector.
 : @return empty sequence.
 :)
declare %private %sequential function xqdoc2html:collect-schema (
  $schemaURI as xs:string, 
  $fileName as xs:string, 
  $collector) 
{
  if(empty($xqdoc2html:schemasCollector/schema[@uri=$schemaURI])) then
    insert node <schema uri="{$schemaURI}" file="{$fileName}" /> as last into $collector;
  else ();
};

(:~
 : This function adds a new record into the $collector.
 : @param $xqdoc the XQDoc xml node.
 : @param $relativeFileName the relative path to the module.
 : @param $collector the name of the collector.
 : @return empty sequence.
 :)
declare %private %sequential function xqdoc2html:collect-functions(
  $xqdoc,
  $relativeFileName as xs:string,
  $collector)
{
  {
    insert nodes
      for $function in $xqdoc/xqdoc:functions/xqdoc:function
      let $name := fn:substring-after($function/xqdoc:name/text(),':'),
          $signature := $function/xqdoc:signature/text(),
          $arity := $function/@arity,
          $isDeprecated := fn:exists($function/xqdoc:comment/xqdoc:deprecated)
      (: use only the functions not marked as %private:)
      where xqdoc2html:function-is-not-private($function)
      order by $name, $arity
      return
        <function moduleUri="{$xqdoc/xqdoc:module/xqdoc:uri/text()}"
                  file="{$relativeFileName}"
                  name="{$name}"
                  signature="{$function/xqdoc:signature/text()}"
                  arity="{$arity}"
                  isDeprecated="{fn:exists($function/xqdoc:comment/xqdoc:deprecated)}"/>
    as last into $collector;
    
    fn:trace(fn:count($xqdoc/xqdoc:functions/xqdoc:function), " number of functions in the module");
    
   }
     
   $collector
};

(:~
 : This function returns a sequence containing all the distinct items 
 : that appear in $arg1 but not in $arg2, in an arbitrary order.
 :
 : @param $arg1 first sequence.
 : @param $arg2 second sequence.
 : @return $arg1-$arg2.
 :)
declare %private function  xqdoc2html:value-except(
  $arg1 as xs:anyAtomicType*,
  $arg2 as xs:anyAtomicType*) as xs:anyAtomicType* 
{
  fn:distinct-values($arg1[not(.=$arg2)])
};

(:~
 : This function returns a sequence containing all the distinct items 
 : that appear in both $arg1 and $arg2, in an arbitrary order.
 :
 : @param $arg1 first sequence.
 : @param $arg2 second sequence.
 : @return $arg1 intersect $arg2.
 :)
declare %private function  xqdoc2html:value-intersect(
  $arg1 as xs:anyAtomicType*,
  $arg2 as xs:anyAtomicType*) as xs:anyAtomicType* 
{
  fn:distinct-values($arg1[.=$arg2])
};

(:~
 : This function returns a sequence containing all the distinct items 
 : that appear in $arg1 and $arg2, in an arbitrary order.
 :
 : @param $arg1 first sequence.
 : @param $arg2 second sequence.
 : @return $arg1 union $arg2.
 :)
declare function xqdoc2html:value-union (
  $arg1 as xs:anyAtomicType*,
  $arg2 as xs:anyAtomicType*) as xs:anyAtomicType* 
{
  fn:distinct-values(($arg1, $arg2))
};
    

(:~
 : The function gathers all the files with the given extensions from the provided $sourcePath
 : and copies them to $destinationPath. The folder structure is not preserved (all files
 : are saved on the same folder level independent of their source folder structure).
 :
 : @param $sourcePath where to search for modules recursively.
 : @param $destinationPath destination folder for the files.
 : @param $extensions The file types to copy as a sequence of extensions strings.
 :    E.g. ("cpp", "h", "xml")
 : @return The empty sequence.
 :)
declare %private %nondeterministic %sequential function xqdoc2html:gather-and-copy(
  $sourcePath       as xs:string,
  $destinationPath  as xs:string, 
  $extensions       as xs:string+)
{
  if(fn:not(file:exists($destinationPath))) then
    ()
  else
    for $extension in $extensions

    for $file in file:list($sourcePath, fn:true(), fn:concat("*.", $extension))

    let $fileName := 
    fn:tokenize($file, fn:concat("\", file:directory-separator()))[last()]

    let $fileSourcePath := fn:concat($sourcePath, file:directory-separator(), $file)

    let $fileDestinationPath := 
    fn:concat($destinationPath, file:directory-separator(), $fileName)

    return
      file:copy($fileSourcePath,$fileDestinationPath)
    
};

(:~
 : Returns the URI of the module given the passed <pre>$folderPath</pre> using
 : the Zorba URI resolving mechanism.
 :
 : @param $folderPath the folder path.
 : @return the URI of the module.
 :)
declare %private function xqdoc2html:get-URI-from-location($folderPath as xs:string) as xs:string {
  let $tok := tokenize($folderPath, fn:concat("\",file:directory-separator()))
  return
    fn:concat('http://', $tok[3],'.', $tok[2],'.', $tok[1], substring-after($folderPath, $tok[3]))
};

(:~ Returns the string resulting from replacing the directory-separators (i.e. / ) with '_'
 :
 : @param $moduleURI the path to the module URI.
 : @return the string resulting from replacing the directory-separators (i.e. / ) with '_'. 
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

(:~
 : The function gathers all the files with the given extensions from the provided $sourcePath
 : and copies them to $destinationPath. The folder structure is not preserved.
 :
 : @param $sourcePath where to search for modules recursively.
 : @param $destinationPath destination folder for the files.
 : @param $extensions The sequence of file types to copy (e.g. ("cpp", "h", "xml")).
 : @return The empty sequence.
 :)
declare %private %nondeterministic %sequential function xqdoc2html:copy-files(
  $sourcePath       as xs:string,
  $destinationPath  as xs:string, 
  $extensions       as xs:string+)
{
  file:create-directory($destinationPath);
  xqdoc2html:gather-and-copy($sourcePath, $destinationPath, $extensions);
};

(:~ 
 : Copy all the external functions implementations (if any)
 :
 : @param $xqPath the path to the .xq.src folder (if any).
 : @param $xqSrcPath the path where the .xq.src will be copied(if it exists).
 : @param $moduleURI the module URI.
 : @return empty string 
 :
 :)
declare %private %nondeterministic %sequential function xqdoc2html:copy-xqsrc-folders(
  $xqPath as xs:string,
  $xqSrcPath as xs:string,
  $moduleURI as xs:string)
{  
  if(file:exists($xqPath)) then
  {
    let $xqSrcFolder := xqdoc2html:get-filename($moduleURI),
        $xqSrcDestinationPath := fn:concat($xqSrcPath, file:directory-separator(), $xqSrcFolder)
              
    return 
    {
      xqdoc2html:copy-files($xqPath, trace($xqSrcDestinationPath," copy external functions implementation in:"), ("cpp", "h"));
    }
  }
  else ();
};

(:~
 : This function gathers schemas found in the $xqdocSchemasPath and fills the $xqdoc2html:schemasCollector.
 : @param $modulePaths the path where the modules can be found.
 : @param $schemasPath the path where the schema files should be copied.
 : @return empty sequence
 :)
declare %private %nondeterministic %sequential function xqdoc2html:gather-schemas(
  $xqdocBuildPath as xs:string,
  $schemasPath as xs:string,
  $zorbaModulesPath as xs:string) 
 {
  (: gather all the config XML's :)
  variable $xqdocXmlConfigPath as xs:string := 
  fn:concat($xqdocBuildPath, file:directory-separator(), "config");
  
  xqdoc2html:create-collection-categories (xs:QName("xqdoc2html:collectionConfig"), $xqdocXmlConfigPath);
  
  
  variable $lPaths := fn:distinct-values(dml:collection(xs:QName("xqdoc2html:collectionConfig"))//module/@moduleRelLocation);
  variable $lPaths1 as xs:string*:= xqdoc2html:value-union(for $lPath in $lPaths where fn:exists($lPath) return xs:string($lPath),$zorbaModulesPath);
  
  (: make sure all the passed paths point to existing folders :)
  variable $lModulePaths as xs:string* := distinct-values(for $lPath in $lPaths1 return
                                                          if($lPath eq xs:string("")) then () 
                                                          else if (file:is-directory($lPath)) then $lPath else () );
 
  for $filedirs in $lModulePaths
  for $file in file:list($filedirs, fn:true(), "*.xsd")
  let $xsdFilePath := concat($filedirs, file:directory-separator(), $file)
  return
    try {
      let $xqdoc := fn:parse-xml(file:read-text($xsdFilePath))
      let $xsdUri := $xqdoc/xs:schema/@targetNamespace
      let $schemaFileName := fn:tokenize($file,fn:concat("\",file:directory-separator()))[fn:last()]
      let $schemaTarget := fn:concat($schemasPath, file:directory-separator(), $schemaFileName)
      return
      {
        xqdoc2html:collect-schema($xsdUri, $schemaFileName, $xqdoc2html:schemasCollector),
        file:copy($xsdFilePath, $schemaTarget)
      }
    } catch * ($error_code, $error_message) {
      fn:error($err:UE005, fn:concat("xqdoc2html:gather-schemas ", $xsdFilePath, " Message: ", $error_message))
    } 
};

(:_____________________________________________________________________________________________________:)

(:~
 : The function copies all the files under the following folders 
 : from $xhtmlRequisitesPath to $xqdocBuildPath/xhtml folder:
 : <ul>
 :  <li>schemas</li>
 :  <li>images</li>
 :  <li>java scripts</li>
 :  <li>css stylesheets</li>
 :  <li>templates</li>
 :  <li>xq.src folders</li>
 : </ul>
 :
 : @param $modulesPath location of the modules.
 : @param $xhtmlRequisitesPath the folder containing the images, lib, styles and templates folders.
 : @param $xqdocBuildPath where to generate the XQDoc XML documents.
 : @return Empty sequence.
 :)
declare %nondeterministic %sequential function xqdoc2html:copy-xhtml-requisites(
  $modulePaths          as xs:string,
  $xhtmlRequisitesPath  as xs:string,
  $xqdocBuildPath       as xs:string,
  $examplePath          as xs:string)
{
  let $xhtmlPath      := fn:concat($xqdocBuildPath, file:directory-separator(), "xhtml"),
      $xmlPath        := fn:concat($xqdocBuildPath, file:directory-separator(), "xml"),
      $schemasPath    := fn:concat($xhtmlPath,      file:directory-separator(), "schemas"),
      $imagesPath     := fn:concat($xhtmlPath,      file:directory-separator(), "images"),
      $libPath        := fn:concat($xhtmlPath,      file:directory-separator(), "lib"),
      $cssPath        := fn:concat($xhtmlPath,      file:directory-separator(), "styles"),
      $templatePath   := fn:concat($xhtmlRequisitesPath,
                                    file:directory-separator(), "templates",
                                    file:directory-separator(), "main.html")
  return
    {
      (: first - create the xhtml folder if it does not exist already :)
      file:create-directory($xhtmlPath);

      (: second - clear the XHTML folder :)
      if(file:exists($xhtmlPath)) then
        file:delete(fn:trace($xhtmlPath, " delete XHTML folder :"));
      else ();      
      
      (: third - re-copy these files :)
      xqdoc2html:copy-files($xhtmlRequisitesPath, fn:trace($imagesPath,   " copy images in :"), ("gif", "png", "svg"));
      xqdoc2html:copy-files($xhtmlRequisitesPath, fn:trace($libPath,      " copy scripts in :"), "js");
      xqdoc2html:copy-files($xhtmlRequisitesPath, fn:trace($cssPath,      " copy stylesheets in :"), "css");
      
      (:TODO replace this: find the schema file location starting from the import schema statement in the XQDoc XML :)     
      file:create-directory($schemasPath);
      xqdoc2html:gather-schemas($xqdocBuildPath, fn:trace($schemasPath," copy schemas in :"), fn:concat($examplePath,file:directory-separator(), "modules"));      
    }
};

(:_____________________________________________________________________________________________________:)

declare %private %sequential function xqdoc2html:create-general-menu($moduleUri as xs:string)
{
  {
    variable $allStructures     := for $entry in $xqdoc2html:menuEntries/entry return $entry/@structure;   
    variable $dvStructures      := distinct-values($allStructures);  
    variable $structures        := for $entry in $dvStructures order by lower-case($entry) return $entry; 
    variable $leftMenuFunction  := xqdoc2html:create-left-menu($moduleUri);
    
    xqdoc2html:create-module-table( $structures,
                                    $leftMenuFunction)
  }
};

declare %nondeterministic %sequential function xqdoc2html:create-collection-categories (
$collectionName as xs:QName,
$xqdocXmlPath as xs:string)
{
  ddl:create-collection($collectionName);
  
  (: gather all the XQDoc XML's :)
  for $xqdocRelPath in file:list($xqdocXmlPath, fn:false(), "*.xml")
  let $path := fn:concat($xqdocXmlPath, file:directory-separator(), $xqdocRelPath )
  let $xqdoc := fn:parse-xml(file:read-text($path))
  return dml:apply-insert-nodes($collectionName, $xqdoc);
};

(:~
 : This function creates the XQDoc XMLs and from them the XQDoc XHTMLs.
 :
 : @param $leftMenu the menu containing the links to the generated XHTMLs.
 : @param $modulePath where to search for .xq modules recursively.
 : @param $xqdocBuildPath where to output the XQDoc XMLs and XHTMLs.
 : @param $indexHtmlPath where to load the template for the index.html.
 : @param $zorbaPath path to zorba dir, usefull to compute absolute path of examples 
 :        from internal modules
 : @param $zorbaVersion Zorba version.
 : @return Empty sequence.
 :)
declare %nondeterministic %sequential function xqdoc2html:main(
  $modulePath     as xs:string , 
  $xqdocBuildPath as xs:string,
  $indexHtmlPath  as xs:string,
  $zorbaPath      as xs:string,
  $zorbaVersion   as xs:string,
  $xhtmlRequisitesPath as xs:string)  
{
  variable $xqdocXmlPath as xs:string := 
  fn:concat($xqdocBuildPath, file:directory-separator(), "xml");
  
  variable $xqdocXhtmlPath as xs:string := 
  fn:concat($xqdocBuildPath, file:directory-separator(), "xhtml");
   
  (: if there is no main.html template we can not proceed further :) 
  if(not(file:exists($indexHtmlPath))) then
    fn:error($err:UE002, "No 'main.html' template was found.");
  else
    ();
    
  (: start generate the XQDoc XHTML for all the modules :)
  
  xqdoc2html:create-collection-categories (xs:QName("xqdoc2html:collection"), $xqdocXmlPath);
  
  trace(xs:string(1)," collect-menu-entries");
  xqdoc2html:collect-menu-entries();
  
  (: test if it's better to create the node once and copy it after raplacing the value we need :)
  (:variable $generalLeftMenu := xqdoc2html:create-general-menu(); :)
                                          
  xqdoc2html:generate-xqdoc-xhtml((:$generalLeftMenu, :) $xhtmlRequisitesPath, $xqdocXhtmlPath, $zorbaPath); 

  variable $generalLeftMenu := xqdoc2html:create-general-menu($xqdoc2html:functionIndexPageName);
  variable $functionIndex := 
  xqdoc2html:generate-function-index-xhtml( $generalLeftMenu,
                                            $indexHtmlPath, 
                            fn:trace(fn:concat($xqdocXhtmlPath, 
                                              file:directory-separator(), 
                                              $xqdoc2html:functionIndexPageName)," create function index page"));
                                              
   
  variable $indexLeftMenu := xqdoc2html:create-general-menu("index.html");
    
  variable $doc := 
    xqdoc2html:generate-index-html($indexHtmlPath,
                                   $indexLeftMenu, 
                                   $indexLeftMenu, 
                                   $zorbaVersion);
  file:write(fn:concat($xqdocXhtmlPath, file:directory-separator(), "index.html"),
             $doc, 
             $xqdoc2html:serParamXhtml);
             
   variable $leftMenuSearch := xqdoc2html:create-general-menu($xqdoc2html:searchPageName);
   variable $search := xqdoc2html:generate-search-xhtml($leftMenuSearch, $indexHtmlPath, $zorbaVersion);
   
   file:write(fn:concat($xqdocXhtmlPath, file:directory-separator(), $xqdoc2html:searchPageName),
             $search, 
             $xqdoc2html:serParamXhtml);
                                             
                         
  dml:delete-nodes(dml:collection(xs:QName("xqdoc2html:collection")));                           
  ddl:delete-collection(xs:QName("xqdoc2html:collection"));
  
  dml:delete-nodes(dml:collection(xs:QName("xqdoc2html:collectionConfig")));                           
  ddl:delete-collection(xs:QName("xqdoc2html:collectionConfig"));
  
};

declare %private function xqdoc2html:get-module-path(
  $moduleUri as xs:string
) as xs:string
{
  dml:collection(xs:QName("xqdoc2html:collectionConfig"))/module[@moduleURI=$moduleUri]/@modulePath
};

declare %private function xqdoc2html:get-examples-path(
  $moduleUri as xs:string
  ) as xs:string
{
  dml:collection(xs:QName("xqdoc2html:collectionConfig"))/module[@moduleURI=$moduleUri]/@examplePath
};

(:~
 : This function reads the XQDoc XML and then invokes the creation of the XHTML
 : for all the modules corresponding to the XML's found in $xqdocXmlPath 
 : and writes the resulting XHTML's in $xqdocXhtmlPath. 
 : The hierarchy is not preserved.
 :
 : @param $xhtmlRequisitesPath location of the XHTML prerequisites.
 : @param $xqdocXhtmlPath where to generate the XQDoc XHTML documents.
 : @param $zorbaPath path to zorba source dir
 : @return A string sequence with a status message for each processed module.
 :)
declare %nondeterministic %sequential function xqdoc2html:generate-xqdoc-xhtml(
  (:$generalLeftMenu, :)
  $xhtmlRequisitesPath  as xs:string,
  $xqdocXhtmlPath       as xs:string,
  $zorbaPath            as xs:string
  ) as xs:string*
{  
  variable $modulePath  := fn:concat($xqdocXhtmlPath, file:directory-separator(), $xqdoc2html:moduleFolderName); 
  variable $extFuncPath := fn:concat($xqdocXhtmlPath, file:directory-separator(), $xqdoc2html:xqFolderName);
  variable $examplesFolderDestination := fn:concat($xqdocXhtmlPath, file:directory-separator(),$xqdoc2html:exampleFolderName); 
  file:create-directory($modulePath);  
  file:create-directory($extFuncPath);
  file:create-directory($examplesFolderDestination);
  
  for $docNode in dml:collection(xs:QName("xqdoc2html:collection"))
  let $moduleDoc := $docNode/xqdoc:xqdoc/xqdoc:module
  let $moduleName := $moduleDoc/xqdoc:name
  let $moduleUri := xs:string(data($moduleDoc/xqdoc:uri))
  let $getFilename := xqdoc2html:get-filename($moduleUri)
  let $xhtmlRelativeFilePath := fn:concat($getFilename, ".html")
  return
  try 
  {
    if(($moduleUri = "http://www.w3.org/2005/xpath-functions") or
       ($moduleUri = "http://www.functx.com/")) then
    {
      (:these modules never change, they have no tests, no external functions, and so on:)
      (:just read the content from the templates folder and compute the left menu:)
      variable $templatesPath := concat($xhtmlRequisitesPath, file:directory-separator(), 'templates');
      variable $xhtmlSource := concat($templatesPath, file:directory-separator(), $xhtmlRelativeFilePath);
                                      
      variable $generalLeftMenu := xqdoc2html:create-general-menu($moduleUri);
      variable $specializedLeftMenu := xqdoc2html:create-specialized-left-menu($generalLeftMenu, $moduleUri);
      
      variable $xhtml := xqdoc2html:add-left-menu($moduleUri, $specializedLeftMenu, $xhtmlSource, $xqdocXhtmlPath);
      variable $xhtmlFilePath := fn:concat($xqdocXhtmlPath, file:directory-separator(), $xhtmlRelativeFilePath);
      file:write(fn:trace($xhtmlFilePath," write XQDoc XHTML"), $xhtml, $xqdoc2html:serParamXhtml);
    }
    else
    {      
      (: replace the inlined examples with actual XQuery code :)
      variable $examplesPath := xqdoc2html:get-examples-path($moduleUri);
      if($examplesPath eq "") then
        $examplesPath := $zorbaPath;
      else ();
      variable $xqdoc2 := xqdoc2html:configure-xml($docNode/xqdoc:xqdoc, $examplesPath, $xqdocXhtmlPath);
      
      (: copy the examples listed in the .xq file into the xhtml/examples folder :)
      xqdoc2html:copy-examples($xqdoc2, $examplesFolderDestination, $examplesPath);
      
      (: copy the .xq module to the xhtml/modules folder :)
      variable $modulefilePath := xqdoc2html:get-module-path($moduleUri);
      variable $destination := fn:concat($modulePath, file:directory-separator(), pxqdoc:get-filename($moduleUri),".xq");
      file:copy($modulefilePath, $destination);
      
      (: copy the implementation of the external functions :)
      xqdoc2html:copy-xqsrc-folders(fn:concat($modulefilePath,".src"), 
                                    $extFuncPath,
                                    $moduleUri);
                                    
      if($xqdoc2/xqdoc:module/@type = "library") then
      {
        variable $generalLeftMenu := xqdoc2html:create-general-menu($moduleUri);
        variable $specializedLeftMenu := xqdoc2html:create-specialized-left-menu($generalLeftMenu, $moduleUri);
         
        variable $templatePath := fn:concat($xhtmlRequisitesPath, file:directory-separator(),"templates",file:directory-separator(),"main.html");
        variable $xhtml := xqdoc2html:doc($xqdoc2, $specializedLeftMenu, $templatePath, $xqdocXhtmlPath);
        xqdoc2html:configure-xhtml($xhtml);
        variable $xhtmlFilePath := fn:concat($xqdocXhtmlPath, file:directory-separator(), $getFilename,".html");
        file:write(fn:trace($xhtmlFilePath," write XQDoc XHTML"), $xhtml, $xqdoc2html:serParamXhtml);
      }
      else ();
    }
  }
  catch * ($error_code, $error_message) 
  {      
    fn:error($err:UE004, fn:concat("FAILED: ", $moduleUri, " Message: ", $error_message));
  }
};

(:~
 : This function does some additional processing for the $xml like
 : replacing examples with actual links to files.
 :
 : @param $xqdoc the node containing the XQDoc XML.
 : @param $examplePath string with the paths where the examples are kept
 :        separated by <pre>;</pre>.
 : @param $xqdocXhtmlPath where to generate the XQDoc XHTML documents.
 : @return the processed $xhtml.
 :)
declare %private %nondeterministic %sequential function xqdoc2html:configure-xml (
  $xqdoc,
  $examplePath as xs:string,
  $xqdocXhtmlPath as xs:string)
{    
  (: replace the inlineExamples with actual inline code :)  
  for $inlineExample in $xqdoc//*:inlineexample
  return
  {
    variable $exampleSource := xqdoc2html:resolve-file-path(fn:data($inlineExample/@href), $examplePath);
    variable $exampleContent := file:read-text($exampleSource);
    replace node $inlineExample with
      <pre class="brush: xquery;">{text{$exampleContent}}</pre>;      
  }
 
  $xqdoc
};

(:~
 : This method copies all the examples and inlineexamples to the $xqdocXhtmlPath/examples folder.
 :
 : @param $xqdoc the node containing the XQDoc XML.
 : @param $xqdocXhtmlPath location where the resulting Xhtml will be saved on disk.
 : @param $examplePath string with the paths where the examples are kept separated by ; .
 : @return The created XHTML page.
 :)
declare %nondeterministic %sequential function xqdoc2html:copy-examples(
  $xqdoc, 
  $examplesFolderDestination as xs:string,
  $examplePath as xs:string)
{
  (:copy the @examples:)
  {
    variable $noExamples := count($xqdoc/xqdoc:functions/xqdoc:function/xqdoc:comment/xqdoc:custom[@tag="example"]);
    if($noExamples ne xs:integer(0)) then
      trace($noExamples,
          " number of examples processed");
    else ();
    for $example in $xqdoc/xqdoc:functions/xqdoc:function/xqdoc:comment/xqdoc:custom[@tag="example"]
    let $exampleText := xqdoc2html:get-example-filename($example/text())
    let $exampleDestination := fn:concat($examplesFolderDestination, "/", $exampleText)
    return 
    {
      variable $exampleSource := fn:concat($examplePath, "/", $example/text());
      if(not(file:is-file($exampleSource))) then
        fn:error($err:UE009, fn:concat("Copy example from <", $exampleSource,"> to <", $exampleDestination, "> failed."))
      else
      try {         
        xqdoc2html:copy-example($exampleSource, $exampleDestination, $examplePath)
      } catch * ($error_code, $error_message) {
        fn:error($err:UE009, fn:concat("Copy example from <", $exampleSource,"> to <", $exampleDestination, "> failed. Error code: ", $error_code, " Message: ", $error_message))
      }
      
    };
  }
};

(:~
 : This function resolves a relative file path given a directory path. The
 : function will fail throwing an error if the destination directory does not
 : exist or if the resulting path does not point to an existing file.
 :
 : @param $relativeFilePath the module file name.
 : @param $directoryPath string with the paths where the examples are kept
 :        separated by <pre>;</pre>.
 : @return The full path of the file to be resolved.
 :)
declare %private %nondeterministic %sequential function xqdoc2html:resolve-file-path(
  $relativeFilePath as xs:string,
  $directoryPath as xs:string
) as xs:string
{
  (: $directoryPath is zorba_folder/test :)
  if (file:is-directory($directoryPath)) then
    let $fullPath := fn:concat($directoryPath, file:directory-separator(), $relativeFilePath)
    return
      if (file:is-file($fullPath)) then
        $fullPath
      else
        fn:error($err:UE008, fn:concat("The file <", $relativeFilePath, "> ",
          "was not found in the directory <", $directoryPath, ">"))
  else
    fn:error($err:UE010, fn:concat("The path <", $directoryPath, "> must point to an existing directory:"))
};

declare %private %nondeterministic %sequential function xqdoc2html:copy-example(
  $exampleSource as xs:string,
  $exampleDestination as xs:string,
  $examplePath as xs:string)
{
  (:file:copy($exampleSource,$exampleDestination) :)
  let $search-queries := fn:concat("rbkt[", file:directory-separator(), file:directory-separator(), "//]Queries")
  return
    if (fn:not(fn:matches($exampleSource, "[.]xq$")) or
        fn:not(fn:matches($exampleSource, $search-queries))) then
      file:copy($exampleSource, $exampleDestination)
    else 
      let $exampleContent := file:read-text( $exampleSource )
      return
      if (fn:matches($exampleContent, "output", "i")) then
        file:copy($exampleSource, $exampleDestination)
      else
        let $specSource := fn:replace($exampleSource, "[.]xq$", ".spec")
        return
        if (fn:matches($specSource, "[.]spec$") and file:is-file($specSource)) 
        then 
        {
          variable $specContent :=  file:read-text( $specSource );

          variable $specContent2 := fn:replace($specContent,
                                              "\$RBKT_SRC_DIR", 
                                              fn:concat($examplePath,"/rbkt"));

          variable $specLines := fn:tokenize($specContent2, "[\n\r]+");

          variable $specArgs := xqdoc2html:parse-spec-args($exampleSource, $specLines);

          variable $specResults := xqdoc2html:parse-spec-results($exampleSource, 
                                                                $specLines);

          variable $exampleContent := fn:concat($exampleContent, "



(: Example configuration (taken from zorba testsuite):

", $specContent2, "

---------------------------------------------------------------------------------------
", $specArgs, "

---------------------------------------------------------------------------------------

", $specResults, "
");
          if (fn:string-length($specResults) eq 0) 
          then
          {
            if (fn:not(matches($specContent2, "Error"))) 
            then
            {
              variable $replace-exp-result := "rbkt/ExpQueryResults";

              variable $exp-result-path := 
              fn:replace($exampleSource, $search-queries, $replace-exp-result);

              variable $exp-result := fn:replace($exp-result-path, "[.]xq$", ".xml.res");

              if (($exp-result-path ne $exampleSource) and file:is-file($exp-result))
              then
              {
                variable $output-content := file:read-text ($exp-result);
                variable $exampleContent := fn:concat ($exampleContent, "
Expected output:

",
$output-content,
"

:)
");
                file:write($exampleDestination, 
                           $exampleContent, 
                           $xqdoc2html:serParamText);
              }
              else
              {
                fn:error($err:UE008, fn:concat("The example <", $exampleSource,"> does not have expected output. Add the example input and expected output by hand in the example, in a commentary that should also include the word 'output'."));
              }
            }
            else
            {
              variable $exampleContent := fn:concat($exampleContent, "

Test returns an error code.
:)
");
              file:write($exampleDestination, $exampleContent, $xqdoc2html:serParamText);
            }
          }
          else
          {
            variable $exampleContent := fn:concat($exampleContent, "

:)
");
            file:write($exampleDestination, $exampleContent, $xqdoc2html:serParamText);
          }
        }
        else
        {
          variable $replace-exp-result := "rbkt/ExpQueryResults";

          variable $exp-result-path := fn:replace($exampleSource, $search-queries, $replace-exp-result);

          variable $exp-result := fn:replace($exp-result-path, "[.]xq$", ".xml.res");

          if (($exp-result-path ne $exampleSource) and file:is-file ($exp-result)) 
          then
          {
            variable $output-content := file:read-text ($exp-result);

            variable $exampleContent := fn:concat ($exampleContent, "

(:

Expected output:

", $output-content, "
                
:)
");

            file:write($exampleDestination, $exampleContent, $xqdoc2html:serParamText);
          }
          else
          {
            fn:error($err:UE008, fn:concat("The example <", $exampleSource,"> does not have expected output. Add the example input and expected output by hand in the example, in a commentary that should also include the word 'output'."));
          }
        }
};

declare %private %nondeterministic %sequential function xqdoc2html:parse-spec-args(
  $exampleSource as xs:string,
  $specLines as xs:string*) as xs:string
{
  if(fn:empty($specLines)) then
    ""
  else
    let $specLine := $specLines[1]
    return
    if(fn:matches($specLine, "Args:")) then
      let $arg_split := fn:substring-after($specLine, "-x")
      return
      if(fn:string-length($arg_split) eq 0) then
        fn:error($err:UE008, fn:concat("Unknown Args: in spec file for example <", $exampleSource,"> .
        Add the example input and expected output by hand in the example, in a commentary that should also include the word 'output'."))
      else
        let $var_value := fn:tokenize($arg_split, "=")
        let $var_name := fn:normalize-space(fn:replace($var_value[1], ":$", ""))
        let $val_path := fn:normalize-space($var_value[2])
        return
        if(fn:matches($val_path, "[.]xml$")) then
          let $var_text := file:read-text( $val_path )
          let $var_size := fn:string-length($var_text)
          return
            if( $var_size lt 2048 ) then
              fn:concat("
Example input xml for variable $", $var_name, ":
",$var_text,
"
",
              xqdoc2html:parse-spec-args($exampleSource, fn:subsequence($specLines, 2)))
            else
              fn:error($err:UE008, fn:concat("The input xml for variable $", $var_name, "in example <", $exampleSource,"> is bigger than 2KB.
              Add the example input and expected output by hand in the example, in a commentary that should also include the word 'output'."))
        else
          xqdoc2html:parse-spec-args($exampleSource, fn:subsequence($specLines, 2))
    else
      xqdoc2html:parse-spec-args($exampleSource, fn:subsequence($specLines, 2))

};

declare %private %nondeterministic %sequential function xqdoc2html:load-expected-results(
  $result_split as xs:string*) as xs:string
{
  if(fn:empty($result_split)) then
    ""
  else
    let $result_path := $result_split[1]
    let $result_text := file:read-text( $result_path )
    let $nonlast_result := if(fn:count($result_split) gt 1) then "
Or equivalent
" else ""
    return
    fn:concat("Expected output:

",$result_text,
"
",
$nonlast_result,
 xqdoc2html:load-expected-results(fn:subsequence($result_split, 2)))
};

declare %private %nondeterministic %sequential function xqdoc2html:parse-spec-results(
  $exampleSource as xs:string,
  $specLines as xs:string*) as xs:string
{
  if(fn:empty($specLines)) then
    ""
  else
    let $specLine := $specLines[1]
    return
    if(fn:matches($specLine, "Result:")) then
      let $result_split := fn:tokenize(fn:normalize-space(fn:substring-after($specLine, "Result:")), "[ \t]")
      return
      if(fn:count($result_split) lt 1) then
        ""
      else
        xqdoc2html:load-expected-results($result_split)
    else
      xqdoc2html:parse-spec-results($exampleSource, fn:subsequence($specLines, 2))

};


(:~
 : This function returns true if there are external functions declared.
 : @param $xqdoc the xqdoc functions.
 : @return a xs:boolean if there are external functions declared.
 :)
declare %private %sequential function xqdoc2html:contains-external-functions (
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

declare %private function xqdoc2html:get-example-filename($examplePath as xs:string) as xs:string 
{
  if (fn:contains($examplePath,"/")) then
    fn:replace($examplePath,"/","_")
  else if (fn:contains($examplePath,"\")) then
    fn:replace($examplePath,"\","_")
  else
    $examplePath
};

declare  %private function xqdoc2html:get-example-filename-link($examplePath as xs:string) as xs:string 
{
  fn:tokenize($examplePath,fn:concat("\",file:directory-separator()))[last()]
};

(:~
 : This function does some additional processing for the $xhtml like
 : replacing the function type description with images, 
 : replacing the function names description with images+name of the functions.
 : @param $xhtml the node containing the XHTML file.
 : @return the processed $xhtml.
 :)
declare %sequential function xqdoc2html:configure-xhtml (
  $xhtml)
{
  (: replace the function type description with images :)  
  let $xquSpec := "http://www.w3.org/TR/xquery-update-10/",
      $xqsSpec := "http://www.w3.org/TR/xquery-sx-10/#dt-sequential-function",
      $xq11Spec := "http://www.w3.org/TR/xquery-11/#FunctionDeclns",
      $xqExternal := "http://www.w3.org/TR/xquery-30/#dt-external-function"
  let $imagesPath := "images/"
  for $typeTd in $xhtml//*:td
  where $typeTd/@class eq "type"
  let $type := $typeTd/text()
  return {
    if (contains($type, "updating ")) then
      replace node $typeTd/text() with
        <span class="no_underline">
          <a href="{$xquSpec}" title="updating" target="_blank"><img src="{concat($imagesPath, "U.gif")}" /></a>
          {if(contains($type, " external")) then
           <a href="{$xqExternal}" title="external" target="_blank"><img src="{concat($imagesPath, "E.gif")}" /></a>
           else ()}
        </span>          
    else if (contains($type, "sequential ")) then
      replace node $typeTd/text() with
        <span class="no_underline">
          <a href="{$xquSpec}" title="sequential" target="_blank"><img src="{concat($imagesPath, "S.gif")}" /></a>
          {if(contains($type, " external")) then
           <a href="{$xqExternal}" title="external" target="_blank"><img src="{concat($imagesPath, "E.gif")}" /></a>
           else ()}
        </span>
    else if (contains($type, "nondeterministic ")) then
      replace node $typeTd/text() with
        <span class="no_underline">
          <a href="{$xquSpec}" title="%nondeterministic" target="_blank"><img src="{concat($imagesPath, "N.gif")}" /></a>
          {if(contains($type, " external")) then
           <a href="{$xqExternal}" title="external" target="_blank"><img src="{concat($imagesPath, "E.gif")}" /></a>
           else ()}
        </span>
    else if (contains($type, " external")) then
      replace node $typeTd/text() with
        <span class="no_underline">
          <a href="{$xqExternal}" title="external" target="_blank"><img src="{concat($imagesPath, "E.gif")}" /></a>
        </span> 
    else ()
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
  return {
    if (starts-with($funcName, "updating")) then
      replace node $func/text() with
        <span class="no_underline">
          <a href="{$xquSpec}" title="updating" target="_blank"><img src="{concat($imagesPath, "U.gif")}" /></a>
          {if(contains($funcName, " external ")) then
            <a href="{$xqExternal}" title="external" target="_blank"><img src="{concat($imagesPath, "E.gif")}" /></a>
          else ()}          
          {text {fn:replace(fn:replace($funcName,"external "," "),"updating ","")}}
        </span>
        
    else if (starts-with($funcName, "sequential")) then
      replace node $func/text() with
        <span class="no_underline">
          <a href="{$xqsSpec}" title="sequential" target="_blank"><img src="{concat($imagesPath, "S.gif")}" /></a>
          {if(contains($funcName, " external ")) then
            <a href="{$xqExternal}" title="external" target="_blank"><img src="{concat($imagesPath, "E.gif")}" /></a>
          else ()}          
          {text {fn:replace(fn:replace($funcName,"external "," "),"sequential ","")}}
        </span>
        
    else if (starts-with($funcName, "nondeterministic")) then
      replace node $func/text() with
        <span class="no_underline">
          <a href="{$xq11Spec}" title="%nondeterministic" target="_blank"><img src="{concat($imagesPath, "N.gif")}" /></a>
          {if(contains($funcName, " external ")) then
            <a href="{$xqExternal}" title="external" target="_blank"><img src="{concat($imagesPath, "E.gif")}" /></a>
          else ()}          
          {text {fn:replace(fn:replace($funcName,"external "," "),"nondeterministic ","")}}
        </span>
    else if(contains($funcName, "external ")) then
      replace node $func/text() with
        <span class="no_underline">          
          <a href="{$xqExternal}" title="external" target="_blank"><img src="{concat($imagesPath, "E.gif")}" /></a>          
          {text {fn:replace($funcName,"external "," ")}}
        </span>
    else ()
  };
  
  $xhtml
};

(:~
 : This function creates the XQDoc XHTML.
 :
 : @param $xqdoc the node containing the XQDoc XML.
 : @param $menu the menu.
 : @param $templatePath the path to the main.html template.
 : @param $xqdocXhtmlPath location where the resulting Xhtml will be saved on disk.
 : @param $examplePath string with the paths where the examples are kept separated by ; .
 : @return The created XHTML page.
 :)
declare %private %nondeterministic %sequential function xqdoc2html:add-left-menu(
  $moduleUri as xs:string, 
  $menu,
  $templatePath as xs:string,
  $xqdocXhtmlPath as xs:string) {
  let $doc := fn:parse-xml(file:read-text($templatePath))
  return {
    insert nodes $menu
    as last into $doc/*:html/*:body/*:div[@id='main']/*:div[@id='leftMenu'];          

    $doc
  }
};

(:~
 : This function creates the XQDoc XHTML.
 :
 : @param $xqdoc the node containing the XQDoc XML.
 : @param $menu the menu.
 : @param $templatePath the path to the main.html template.
 : @param $xqdocXhtmlPath location where the resulting Xhtml will be saved on disk.
 : @param $examplePath string with the paths where the examples are kept separated by ; .
 : @return The created XHTML page.
 :)
declare %nondeterministic %sequential function xqdoc2html:doc(
  $xqdoc, 
  $menu,
  $templatePath as xs:string,
  $xqdocXhtmlPath as xs:string) {
  let $doc := fn:parse-xml(file:read-text($templatePath))
  return {
    insert node <title>Documentation for {xqdoc2html:module-uri($xqdoc)}</title>
    as first into $doc/*:html/*:head;    
 
    insert nodes $menu
    as last into $doc/*:html/*:body/*:div[@id='main']/*:div[@id='leftMenu'];     

    let $right_content := $doc/*:html/*:body/*:div[@id='main']/*:div[@id='rightcontent']
    return
      if ($right_content)
      then
        insert nodes xqdoc2html:body($xqdoc, $xqdocXhtmlPath)
        as last into $right_content;
      else
        ();
        

    $doc
  }
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
 : This function creates the XQDoc XHTML body.
 :
 : @param $xqdoc the node containing the XQDoc XML.
 : @param $xqdocXhtmlPath location where the resulting Xhtml will be saved on disk.
 : @return The 'body' of the XHTML.
 :)
declare %nondeterministic function xqdoc2html:body(
  $xqdoc, 
  $xqdocXhtmlPath as xs:string)
{
  (: use only the functions not marked as %private :)
  let $functions := for $function in $xqdoc/xqdoc:functions/xqdoc:function 
                    where xqdoc2html:function-is-not-private($function)
                    return $function
  let $moduleUri := xqdoc2html:module-uri($xqdoc)
  let $isZorbaCore as xs:boolean := xs:boolean(dml:collection(xs:QName("xqdoc2html:collectionConfig"))/module[@moduleURI=$moduleUri]/@isCore)
  let $modulePrefix as xs:string := if(count($functions) ne xs:integer(0)) then 
  substring-before($xqdoc/xqdoc:functions/xqdoc:function[1]/xqdoc:name/text(),':') else
  if($xqdoc/xqdoc:variables/xqdoc:variable) then
  substring-before($xqdoc/xqdoc:variables/xqdoc:variable[1]/xqdoc:uri/text(),':') else
  "modNS"
  return
  (<h1>{if ($isZorbaCore) then <sup><img src="images/ZCsmall.gif" alt="ZC" title="This module is part of Zorba core."/></sup> else () }{$moduleUri}</h1>,
    xqdoc2html:module-description($moduleUri, $modulePrefix, $xqdoc/xqdoc:module),
    xqdoc2html:module-resources($xqdocXhtmlPath, xqdoc2html:module-uri($xqdoc)),
    xqdoc2html:module-dependencies($xqdoc),
    xqdoc2html:module-external-specifications($xqdoc/xqdoc:module),
    xqdoc2html:module-variables($xqdoc/xqdoc:variables),
    xqdoc2html:module-function-summary($functions),
    xqdoc2html:functions($functions, $xqdocXhtmlPath)
  )
};

(:~
 : Create the module description and module annotations.
 :
 : @param $module the node containing the XQDoc XML module.
 : @return the XHTML for the module description and module annotations.
 :)
declare function xqdoc2html:module-description($moduleUri as xs:string, $modulePrefix as xs:string, $module) {
    ( <div class="section"><span id="module_description">Module Description</span></div>,
      <span>Before using any of the functions below please remember to import the module namespace:
      <pre class="brush: xquery;">import module namespace {$modulePrefix} = "{$moduleUri}";</pre>
      Also check out the examples that show the parameters( if any) that have to be passed to each function.
      </span>,<br />,
     xqdoc2html:description($module/xqdoc:comment),
     xqdoc2html:annotations-module($module/xqdoc:comment))
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
 : Create the XHTML for all module annotations except these ones:
 : <ul>
 :   <li>description</li>
 :   <li>param</li>
 :   <li>return</li>
 :   <li>error</li>
 :   <li>deprecated</li>
 :   <li>see</li>
 :   <li>library</li>
 : </ul>
 :
 : @param $comment the part of the XQDoc file holding the module annotations.
 : @return the XHTML for the module annotations.
 :)
declare %private function xqdoc2html:annotations-module($comment) {
  let $annotations := $comment/xqdoc:*[not((local-name(.) = ("description", "param", "return", "error", "deprecated", "see", "library", "project")))]
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
 : Create the XHTML for the module resources (the implementation of the external functions).
 :
 : @param $xqSrcPath the path to the xq.src folders.
 : @param $moduleUri the module URI.
 : @param $indexCollector the modules names part of the left menu.
 : @return the XHTML for the 'Module Resources'.
 :)
declare %nondeterministic function xqdoc2html:module-resources(
  $xqdocXhtmlPath as xs:string,
  $moduleUri as xs:string) 
{
  let $folder := xqdoc2html:get-filename($moduleUri),
      $xqSrcPath := fn:concat($xqdocXhtmlPath,file:directory-separator(), $xqdoc2html:xqFolderName)
  return
    (<div class="section"><span id="module_resources">Module Resources</span></div>,
     <ul>
     <li>the XQuery module can be found <a href="modules/{fn:concat(pxqdoc:get-filename($moduleUri),".xq")}" target="_blank">here</a>.</li>
    {if(file:exists(fn:concat($xqSrcPath,file:directory-separator(),$folder,file:directory-separator()))) then
       <li>the implementation of the external functions can be found <a href="{fn:concat($xqdoc2html:xqFolderName,file:directory-separator(),$folder)}" target="_blank">here</a>.</li>
    else
      ()}
      </ul>)
};

(:~
 : Create the XHTML for the module dependencies (imported modules, schemas).
 :
 : @param $xqdoc the node containing the XQDoc XML.
 : @return the XHTML for the 'Module Dependencies'.
 :)
declare function xqdoc2html:module-dependencies(
    $xqdoc) {
  if (fn:count($xqdoc/xqdoc:imports/xqdoc:import) > 0 or
      fn:count($xqdoc/xqdoc:module/xqdoc:comment/xqdoc:*[(local-name(.) = ("library"))]) > 0) then
    (<div class="section"><span id="module_dependencies">Module Dependencies</span></div>,
    xqdoc2html:imports($xqdoc))
  else
    ()
};

(:~
 : Create the items for the module dependencies (imported modules, schemas).
 :
 : @param $xqdoc the node containing the XQDoc XML.
 : @return the XHTML for the 'Module Dependencies'.
 :)
declare %private function xqdoc2html:imports(
    $xqdoc) {
  (
  if (fn:count($xqdoc/xqdoc:imports//xqdoc:import[@type = "library"]) > 0) then
    <p>Imported modules:<ul>
    {
      for $import in $xqdoc/xqdoc:imports//xqdoc:import[@type = "library"]
      return
      (:TODO this is a bug if an external module is imported :)
      (:  if (exists($xqdoc2html:indexCollector/module[@uri=$import/xqdoc:uri/text()])) then
          <li><a href="{$xqdoc2html:indexCollector/module[@uri=$import/xqdoc:uri/text()]/@file}.html">{string($import/xqdoc:uri/text())}</a></li>
        else
          <li>{string($import/xqdoc:uri/text())}</li>
      :)
      <li><a href="{fn:concat(xqdoc2html:get-filename($import/xqdoc:uri/text()) ,'.html')}">{string($import/xqdoc:uri/text())}</a></li>
    }
    </ul></p>
  else (),
  if (fn:count($xqdoc/xqdoc:imports//xqdoc:import[@type = "schema"]) > 0) then
    <p>Imported schemas:<ul>
    {
      for $import in $xqdoc/xqdoc:imports//xqdoc:import[@type = "schema"]
      return
        if (exists($xqdoc2html:schemasCollector/schema[@uri=$import/xqdoc:uri/text()])) then
        {
          let $file := $xqdoc2html:schemasCollector/schema[@uri=$import/xqdoc:uri/text()]/@file,
              $filePath := fn:concat("schemas",file:directory-separator(),$file)
          return
          <li><a href="{$filePath}" target="_blank">{string($import/xqdoc:uri/text())}</a></li>
        }
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
              <td>${$varName}</td>
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
      let $name := fn:substring-after($function/xqdoc:name/text(),':'),
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
            <td class="type">{concat($type," ",$external)}</td>
            <td>
              <tt>{
                if ($isDeprecated) then
                  <span class="functName"><del><a href="#{$name}-{$param-number}" title="{normalize-space($description)}">{$name}</a></del></span>
                else
                  <span class="functName"><a href="#{$name}-{$param-number}" title="{normalize-space($description)}">{$name}</a></span>
              }{xqdoc2html:split-function-signature($paramsAndReturn)}<br /><span class="padding">{$shortDescription}</span>
              </tt>
            </td>
          </tr>
    }</table>
  else
      <p>No <a href="http://www.w3.org/TR/xquery-11/#doc-xquery11-PrivateOption">public</a> functions declared.</p>
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

(:~
 : Create the details for all the functions.
 :
 : @param $functions the node containing the XQDoc XML functions.
 : @param $xqdocXhtmlPath location where the resulting Xhtml will be saved on disk.
 : @return the XHTML for the function details.
 :)
declare %nondeterministic function xqdoc2html:functions($functions, $xqdocXhtmlPath) {
    if(count($functions)) then (
      <div class="section"><span id="functions">Functions</span></div>,
      for $function in $functions
      let $name := fn:substring-after($function/xqdoc:name/text(),':'),
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
 : Append in the beginning of the function name
 : updating, sequential, nondeterministic is applicable.
 :
 : @param $name the function name.
 : @param $signature the signature of the function.
 : @return a new string for the function name.
 :)
declare %private function xqdoc2html:module-function-link($name as xs:string, $signature) {

let $lcSignature := fn:lower-case($signature)
let $lname := if(ends-with($signature, 'external')) then concat('external ',$name) else $name
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
 : Create the XHTML for all function annotations except these ones:
 : <ul>
 :   <li>description</li>
 :   <li>param</li>
 :   <li>return</li>
 :   <li>error</li>
 :   <li>deprecated</li>
 :   <li>see</li>
 :   <li>example</li>
 : </ul>.
 :
 : @param $comment the part of the XQDoc file holding the function annotations.
 : @return the XHTML for the function annotations.
 :)
declare function xqdoc2html:annotations($comment) {
  let $annotations := $comment/xqdoc:*[not((local-name(.) = ("description", "param", "return", "error", "deprecated", "see", "custom")))]
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
declare %nondeterministic function xqdoc2html:annotations-example($comment, $xqdocXhtmlPath) {
  let $example := $comment//xqdoc:custom[@tag="example"]
  return
    if (count($example) = 0) then ()
    else
    (<div class="subsubsection">Examples:</div>,<ul>
    {for $annotation in $example
    return
      if(file:exists(fn:concat($xqdocXhtmlPath, file:directory-separator(), "examples", file:directory-separator(), 
         xqdoc2html:get-example-filename($annotation/node())))) then
        <li><a href="{fn:concat('examples',file:directory-separator(), xqdoc2html:get-example-filename($annotation/node()))}" target="_blank">{xqdoc2html:get-example-filename-link($annotation/node())}</a></li>
      else
        <li>{fn:concat("The example with filename '",$annotation/node(), "' was not found.")}</li>}</ul>
    )
};

declare %private function xqdoc2html:function-is-not-private($function)
{
  not(exists($function//xqdoc:annotation[@localname = 'private']))
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
                  for $docNode in dml:collection(xs:QName("xqdoc2html:collection"))
                  for $function in $docNode/xqdoc:xqdoc/xqdoc:functions//xqdoc:function
                    let $functionName := substring-after($function/xqdoc:name/text(),':')
                    where xqdoc2html:function-is-not-private($function)
                  return upper-case(substring($functionName,1,1)))
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
            for $docNode in dml:collection(xs:QName("xqdoc2html:collection"))
            for $function in $docNode/xqdoc:xqdoc/xqdoc:functions//xqdoc:function
            let $module := $docNode/xqdoc:xqdoc/xqdoc:module,
                $moduleUri := $module/xqdoc:uri/text(),
                $file := fn:concat(pxqdoc:get-filename($moduleUri),'.html'),
                $functionName := fn:substring-after($function/xqdoc:name/text(),':'),
                $signature := $function/xqdoc:signature/text(),
                $arity :=  $function/@arity,
                $isDeprecated := fn:exists($function/xqdoc:comment/xqdoc:deprecated),
                $isExternal := ends-with($signature, "external"),
                $paramsAndReturn :=
                  let $searchCrit := concat(":", $functionName)
                  return
                    if ($isExternal)then
                      normalize-space(substring-before(substring-after($signature, $searchCrit), "external"))
                    else normalize-space(substring-after($signature, $searchCrit))
            where (starts-with($functionName, lower-case($letter)) and
                   xqdoc2html:function-is-not-private($function))
            order by $functionName, $arity
            return
              <tr>
                <td><div class="link">
                  <tt>{
                    if ($isDeprecated eq fn:true()) then
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
 : This function generates the XQDoc function index page.
 : @param $indexFunctionLeft the menu containing the links to the generated Xhtml files.
 : @param $templatePath the path to the main.html template.
 : @return The content of the function index page.
 :)
declare %nondeterministic %sequential function xqdoc2html:generate-function-index-xhtml(
  $indexFunctionLeft,
  $templatePath as xs:string,
  $functionIndexPath as xs:string
) {
  let $indexHtmlDoc := fn:parse-xml(file:read-text($templatePath))
  return {
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
          as last into $right_content;
        else
          ();

    (:$indexHtmlDoc:)
    file:write($functionIndexPath, 
               $indexHtmlDoc, 
               $xqdoc2html:serParamXhtml);
  }
};

declare %private %sequential function xqdoc2html:collect-entry (
  $href as xs:string, 
  $name as xs:string, 
  $structure as xs:string,
  $pureXQuery as xs:string,
  $moduleURI as xs:string) 
{
  insert node <entry  href="{$href}" 
                      name="{$name}" 
                      structure="{$structure}"
                      pureXQuery="{$pureXQuery}"
                      moduleURI="{$moduleURI}" /> as last into $xqdoc2html:menuEntries;
};

declare %private %sequential function xqdoc2html:collect-menu-entries()
{
  for $docNode in dml:collection(xs:QName("xqdoc2html:collection"))
      let $module := $docNode/xqdoc:xqdoc/xqdoc:module,
          $lModuleProject := $module/xqdoc:custom[@tag="project"]/text(),
          $lModuleUri     := $module/xqdoc:uri/text(),
          $lModuleName    := substring-before($module/xqdoc:name/text(),".xq"),  
          $lXHTMLFileName := pxqdoc:get-filename($lModuleUri),
          $lPureXquery    := not(xqdoc2html:contains-external-functions($docNode/xqdoc:xqdoc)),
          $lTmp := substring-after($lModuleUri,'http://'),
          $lTmpTok := tokenize($lTmp,'/'),
          $lTmp2 := if(ends-with($lTmp,'/')) then substring($lTmp,1,string-length($lTmp)-1) else string-join(xqdoc2html:value-except($lTmpTok,$lTmpTok[last()]),'/'),
          $structure  := if(exists($lModuleProject)) then $lModuleProject else $lTmp2
  order by $lModuleProject, $lModuleUri
    return xqdoc2html:collect-entry($lXHTMLFileName,
                                    $lModuleName,
                                    $structure,
                                    xs:string($lPureXquery),
                                    $lModuleUri)
};

(:~
 : This function add the subcategories in the menu.
 :
 : @param $table the parent module category.
 : @param $category the category.
 : @param $moduleUri module URI.
 : @return $table after the subcategory together with the modules were added to it.
 :)
declare %private %sequential function xqdoc2html:create-module-helper(
  $table, 
  $category as xs:string,
  $currentCategory as xs:string
  )
{
  {
    insert nodes <li>{$category}
    <ul>
    {
      for $entry in $xqdoc2html:menuEntries/entry
      let $isZorbaCore as xs:boolean := xs:boolean(dml:collection(xs:QName("xqdoc2html:collectionConfig"))/module[@moduleURI=data($entry/@moduleURI)]/@isCore)
      order by $entry/@structure
      where ($entry/@structure eq $currentCategory)
      return
        <li>
          {
            if($isZorbaCore) then
              <sup><img src="images/ZCsmall.gif" alt="ZC" title="This module is part of Zorba core."/></sup>
            else ()
          }
          <a href="{data($entry/@href)}.html" title="{data($entry/@moduleURI)}">{data($entry/@name)}</a>
          {
            if(xs:boolean(data($entry/@pureXQuery))) then ()
            else
              <span class="superscript"><a href="http://www.w3.org/TR/xquery-30/#dt-external-function" 
              target="_blank" title="There are external functions (either private or public) declared in this module.">(E)</a></span>
          }          
        </li>
    }    
    </ul></li>
    as last into $table
  };

  $table
};

declare %private function xqdoc2html:get-distinct-children (
  $level1 as xs:string*,
  $currentCat as xs:string
) as xs:string*
{
  let $lTmp :=  for $cat in $level1 
                where starts-with($cat,concat($currentCat,'/'))
                return substring-after($cat, concat($currentCat,'/'))
  return distinct-values(for $str in $lTmp return tokenize($str,'/')[1])
};

(:~
 : Recursive helper
 :)
declare %private %sequential function xqdoc2html:create-module-table-rec(
  $level1 as xs:string*,
  $leveln as xs:string*,
  $curentCat as xs:string,
  $table) {
  if(empty($leveln)) then ()
  else
    for $cat in $leveln
    order by lower-case($cat)
    return {
      variable $lCurentCat := if($curentCat eq "") then $cat else concat($curentCat,'/',$cat);
      xqdoc2html:create-module-helper($table, $cat, $lCurentCat);
      xqdoc2html:create-module-table-rec($level1, xqdoc2html:get-distinct-children($level1,$lCurentCat), $lCurentCat,$table/li[fn:last()]/ul)
    }
};

(:~
 : This function creates the categories in the menu.
 :
 : @param $leftMenu the menu.
 : @param $root the root.
 : @param $moduleUri module URI.
 : @return $root after the subcategories were added to it.
 :)
declare %private %sequential function xqdoc2html:create-module-table(
  $level1 as xs:string*, 
  $root) 
{
  {
    variable $leveln := distinct-values(for $str in $level1 return tokenize($str,'/')[1]);
    
    xqdoc2html:create-module-table-rec($level1, $leveln, "", $root);
      
    $root
  }
};


(:~
 : This function creates menu header provided $pageName page.
 :
 : @param $leftMenu the menu.
 : @param $pageName the name of the function index XHTML page.
 : @return $root after the subcategories were added to it.
 :)
declare %private function xqdoc2html:create-left-menu($moduleUri as xs:string)
{
  <ul id="documentation">
    {
    (   
      if($moduleUri = $xqdoc2html:functionIndexPageName) then
        (
        <span><a href="index.html">XQuery Modules Documentation</a></span>,    
        <li><span class="leftmenu_active">Function Index</span></li>,
        <li><a href="{$xqdoc2html:searchPageName}">Search page</a></li>)
      else if($moduleUri = "index.html") then
        (<span class="leftmenu_active">XQuery Modules Documentation</span>,
         <li><a href="{$xqdoc2html:functionIndexPageName}">Function Index</a></li>,
         <li><a href="{$xqdoc2html:searchPageName}">Search page</a></li>)
      else if($moduleUri = $xqdoc2html:searchPageName) then
        (<span><a href="index.html">XQuery Modules Documentation</a></span>,
         <li><a href="{$xqdoc2html:functionIndexPageName}">Function Index</a></li>,
         <li><span class="leftmenu_active">Search page</span></li>)
      else
         (<span><a href="index.html">XQuery Modules Documentation</a></span>,
         <li><a href="{$xqdoc2html:functionIndexPageName}">Function Index</a></li>,
         <li><a href="{$xqdoc2html:searchPageName}">Search page</a></li>),
      
      for $link in $xqdoc2html:externalLinks//a
      return
        <li>{$link}</li>
    )
    }
   </ul>
};

declare %private %sequential function xqdoc2html:create-specialized-left-menu( 
  $generalLeftMenu, 
  $moduleUri as xs:string)
{  
  {
    for $docNode in dml:collection(xs:QName("xqdoc2html:collection"))
      let $module := $docNode/xqdoc:xqdoc/xqdoc:module,
          $lModuleUri     := $module/xqdoc:uri/text(),
          $lPureXquery    := not(xqdoc2html:contains-external-functions($docNode/xqdoc:xqdoc))
    where $lModuleUri = $moduleUri
            
    for $node in $generalLeftMenu//li
    let $isZorbaCore as xs:boolean := xs:boolean(dml:collection(xs:QName("xqdoc2html:collectionConfig"))/module[@moduleURI=$moduleUri]/@isCore)
    where $node/a[@title eq $moduleUri] 
    return   
    replace node $node with
      <li>
      {
        if($isZorbaCore) then
          <sup><img src="images/ZCsmall.gif" alt="ZC" title="This module is part of Zorba core."/></sup>
        else ()
      }
      <span class="leftmenu_active">{$node/a/text()}
      {
        if($lPureXquery) then ()
        else
          <span class="superscript"><a href="http://www.w3.org/TR/xquery-30/#dt-external-function" 
          target="_blank" title="There are external functions (either private or public) declared in this module.">(E)</a></span>
      }</span></li>;      
  }
 
  $generalLeftMenu
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
declare %private %nondeterministic %sequential function xqdoc2html:generate-index-html(
  $templatePath as xs:string, 
  $menu, 
  $modules,
  $zorbaVersion as xs:string) as document-node()
{
    let $indexHtmlDoc := fn:parse-xml(file:read-text($templatePath))
    return {
        insert node <title>XQuery Modules Documentation</title>
        as first into $indexHtmlDoc/*:html/*:head;

        insert nodes $menu
        as last into $indexHtmlDoc/*:html/*:body/*:div[@id='main']/*:div[@id='leftMenu'];

        let $right_content := $indexHtmlDoc/*:html/*:body/*:div[@id='main']/*:div[@id='rightcontent']
        return
          if ($right_content)
          then
            insert nodes
              (<div class="section"><span class="section">Zorba XQuery Processor {$zorbaVersion}</span></div>,
              <p>This document contains a list of all the XQuery modules that come with the Zorba XQuery processor.</p>,
              $modules)
            as last into $right_content;
          else
            ();

        $indexHtmlDoc
    }
};

(:~
 : This function generates the Search page XHTML.
 : @param $indexFunctionLeft the menu containing the links to the generated Xhtml files.
 : @param $templatePath the path to the main.html template.
 : @param $zorbaVersion Zorba version.
 : @return The content of the Search page.
 :)
declare %nondeterministic %sequential function xqdoc2html:generate-search-xhtml(
  $indexFunctionLeft,
  $templatePath as xs:string,
  $zorbaVersion as xs:string
) as document-node() {

  let $searchDoc := fn:parse-xml(file:read-text($templatePath))
  return {
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
          as last into $right_content;
        else
          ();

    $searchDoc
  }
};
