xquery version "3.0";

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
import module namespace fetch = "http://www.zorba-xquery.com/modules/fetch";

import module namespace file = "http://expath.org/ns/file";

import schema namespace xqdoc = "http://www.xqdoc.org/1.0";
import schema namespace output = "http://www.w3.org/2010/xslt-xquery-serialization";

declare namespace an = "http://www.zorba-xquery.com/annotations";
declare namespace werr = "http://www.w3.org/2005/xqt-errors";
declare namespace z = "http://www.zorba-xquery.com/manifest";

declare copy-namespaces preserve, inherit;

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";

(:~
 : the name of the folder where the modules will be copied for the XQDoc documentation
 :)
declare %private variable $xqdoc2html:moduleFolderName as xs:string := "modules";

(:~
 : the name of the folder where the examples will be copied for the XQDoc documentation
 :)
declare %private variable $xqdoc2html:exampleFolderName as xs:string := "examples";

(:~
 :  The QName of the collection containing the XQDoc XML's
 :)
declare %private variable $xqdoc2html:collection as xs:QName := xs:QName("xqdoc2html:collection");
declare collection xqdoc2html:collection as node()*;

(:~
 :  Collector of the entries in the left menu
 :)
declare %private variable $xqdoc2html:menuEntries := <entries/>;

(:~
 :  Collector for the Zorba manifest
 :)
declare %private variable $xqdoc2html:ZorbaManifest := <manifest/>;

(:~
 :  The level 1 wights for the categories in the left menu (this gives the order of the Level1 items)
 :)
declare %private variable $xqdoc2html:level1Weight as xs:string* :=
("www.w3.org", "XDM", "store", "introspection", "reflection",
 "external", "xqdoc","data processing", "programming languages", "excel",
 "cryptography", "geo", "image", "OAuth", "expath.org",
 "www.functx.com", "communication");

(:~
 : This variable contains all the schemas imported by the modules
 :)
declare %private variable $xqdoc2html:schemasCollector := <schemas/>;

(:~
 : The serialization parameters for XML serialization.
 :)
declare %private variable $xqdoc2html:serParamXml :=
  <output:serialization-parameters>
    <output:method value="xml"/>
    <output:indent value="yes"/>
  </output:serialization-parameters>;
(:~
 : The serialization parameters for XHTML serialization.
 :)
declare %private variable $xqdoc2html:serParamXhtml:=
  <output:serialization-parameters>
    <output:method value="xhtml"/>
    <output:indent value="yes"/>
  </output:serialization-parameters>;
(:~
 : The serialization parameters for text serialization.
 :)
declare %private variable $xqdoc2html:serParamText :=
  <output:serialization-parameters>
    <output:method value="text"/>
  </output:serialization-parameters>;

(:~
 : This is the name of the function index XHTML page.
 :)
declare %private variable $xqdoc2html:functionIndexPageName as xs:string := "function_index.html";

(:_____________________________________________________________________________________________________:)

(:~
 : This function adds a new record into the $collector.
 : @param $schemaURI the schema URI.
 : @param $fileName the schema file name.
 : @param $collector the name of the collector.
 : @return empty sequence.
 :)
declare %private %an:sequential function xqdoc2html:collect-schema (
  $schemaURI as xs:string,
  $fileName as xs:string,
  $collector)
{
  insert node <schema uri="{$schemaURI}" file="{$fileName}" /> as last into $collector;
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
declare %private %an:sequential function xqdoc2html:gather-and-copy(
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
 : Returns the string resulting from replacing the directory-separators (i.e. // ) with '_'
 :
 : @param $moduleURI the path to the module URI.
 : @return the string resulting from replacing the directory-separators (i.e. // ) with '_'.
 :
 :)
declare function xqdoc2html:get-filename($moduleURI as xs:string) as xs:string {
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
declare %private %an:sequential function xqdoc2html:copy-files(
  $sourcePath       as xs:string,
  $destinationPath  as xs:string,
  $extensions       as xs:string+)
{
  file:create-directory($destinationPath);
  xqdoc2html:gather-and-copy($sourcePath, $destinationPath, $extensions);
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
 : @param $xhtmlRequisitesPath the folder containing the images, lib, styles and templates folders.
 : @param $xqdocBuildPath where to generate the XQDoc XML documents.
 : @return Empty sequence.
 :)
declare %an:sequential function xqdoc2html:copy-xhtml-requisites(
  $xhtmlRequisitesPath  as xs:string,
  $xqdocBuildPath       as xs:string) as empty-sequence()
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
      if(file:exists($xhtmlPath)) then
        file:delete($xhtmlPath);
      else ();

      file:create-directory($xhtmlPath);

      xqdoc2html:copy-files($xhtmlRequisitesPath, $imagesPath ,("gif", "png", "svg"));
      xqdoc2html:copy-files($xhtmlRequisitesPath, $libPath    ,"js");
      xqdoc2html:copy-files($xhtmlRequisitesPath, $cssPath    ,"css");

      file:create-directory($schemasPath);
    }
};

(:_____________________________________________________________________________________________________:)

declare %private %an:sequential function xqdoc2html:create-general-menu()
{
  {
    variable $allStructures     := for $entry in $xqdoc2html:menuEntries/entry return $entry/@structure;
    variable $dvStructures      := distinct-values($allStructures);
    variable $structures        := for $entry in $dvStructures order by lower-case($entry) return $entry;
    variable $leftMenuFunction  := xqdoc2html:create-left-menu();

    xqdoc2html:create-module-table( $structures,
                                    $leftMenuFunction)
  }
};

declare %private %an:sequential function xqdoc2html:create-collection-categories (
$collectionName as xs:QName,
$xqdocXmlPath as xs:string)
{
  ddl:create($collectionName);

  (: gather all the XQDoc XML's :)
  for $xqdocRelPath in file:list($xqdocXmlPath, fn:false(), "*.xml")
  let $path := fn:concat($xqdocXmlPath, file:directory-separator(), $xqdocRelPath )
  let $xqdoc := fn:parse-xml(file:read-text($path))
  return dml:apply-insert-nodes($collectionName, $xqdoc);
};

declare %private %an:sequential function xqdoc2html:collectZorbaManifestEntries(
  $zorbaManifestPath as xs:string,
  $xqdocBuildPath as xs:string)
{
  if(not(file:is-file($zorbaManifestPath))) then
  {
    variable $message := fn:concat("The file <ZorbaManifest.xml> was not found: <", $zorbaManifestPath, ">. Suggestion: run 'cmake' in your build folder such that ZorbaManifest.xml is regenerated.");
    fn:error($err:UE004, $message);
  }
  else
  try
  {
    variable $manifestXML := fn:parse-xml(file:read-text($zorbaManifestPath));

    variable $moduleManifests := $manifestXML/z:manifest/z:module;
      
    for $module in $moduleManifests
    let $uri := $module/z:uri/text()
    group by $uri
    let $module := if(count($module) gt 1) then $module[@version = max($module/@version)] else $module
    return
      insert node <module uri="{$uri}"
                          isCore="{data($module/@isCore)}"
                          version="{if (exists(data($module/@version))) then data($module/@version) else ''}"
                          projectRoot="{data($module/z:projectRoot)}"/> as last into $xqdoc2html:ZorbaManifest;
  }
  catch *
  {
    fn:error(fn:concat("The file <",$zorbaManifestPath,"> does not have the correct structure."));
  }
};

(:~
 : This function creates the XQDoc XMLs and from them the XQDoc XHTMLs.
 :
 : @param $zorbaManifestPath location of ZorbaManifest.xml.
 : @param $xqdocBuildPath where to output the XQDoc XMLs and XHTMLs.
 : @param $indexHtmlPath where to load the template for the index.html.
 : @param $zorbaVersion Zorba version.
 : @param $xhtmlRequisitesPath the path where the XHTML requisites are stored.
 : @return Empty sequence.
 :)
declare %an:sequential function xqdoc2html:main(
  $zorbaManifestPath as xs:string,
  $xqdocBuildPath as xs:string,
  $indexHtmlPath  as xs:string,
  $zorbaVersion   as xs:string,
  $xhtmlRequisitesPath as xs:string) as empty-sequence()
{
  (: fill out $xqdoc2html:ZorbaManifest :)
  xqdoc2html:collectZorbaManifestEntries($zorbaManifestPath, $xqdocBuildPath);

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

  trace(xs:string(1)," collect-menu-entries ...");
  xqdoc2html:collect-menu-entries();

  (: copy the left menu inside menu.html page :)
  trace(xs:string(2)," create-general-menu ...");
  variable $leftMenuIndex := xqdoc2html:create-general-menu();
  variable $generalLeftMenu :=  <ul id="documentation" class="treeview">{$leftMenuIndex}</ul>;

  xqdoc2html:generate-xqdoc-xhtml($generalLeftMenu, $xhtmlRequisitesPath, $xqdocXhtmlPath);

  variable $functionIndex :=
  xqdoc2html:generate-function-index-xhtml( $generalLeftMenu,
                                            $indexHtmlPath,
                                            fn:concat($xqdocXhtmlPath,
                                              file:directory-separator(),
                                              $xqdoc2html:functionIndexPageName));

  variable $doc :=
    xqdoc2html:generate-index-html($indexHtmlPath,
                                   $generalLeftMenu,
                                   $leftMenuIndex,
                                   $zorbaVersion);

  file:write(fn:concat($xqdocXhtmlPath, file:directory-separator(), "index.html"),
             $doc,
             $xqdoc2html:serParamXhtml);

  dml:delete-nodes(dml:collection(xs:QName("xqdoc2html:collection")));
  ddl:delete(xs:QName("xqdoc2html:collection"));
  
  (:delete modules_new.svg if it exists:)
  variable $SVGGraph := fn:concat($xhtmlRequisitesPath,
                        file:directory-separator(),
                        "images",
                        file:directory-separator(),
                        "modules_new.svg");

  if(file:exists($SVGGraph)) then
        file:delete($SVGGraph);
  else ();
};

declare %private function xqdoc2html:get-project-root(
  $moduleUri as xs:string
  ) as xs:string
{
  xs:string(data($xqdoc2html:ZorbaManifest/module[@uri= $moduleUri]/@projectRoot))
};

declare %private function xqdoc2html:get-is-core(
  $moduleUri) as xs:boolean
{
  xs:boolean(data($xqdoc2html:ZorbaManifest/module[@uri= $moduleUri]/@isCore))
};

declare %private function xqdoc2html:get-module-version(
  $moduleUri) as xs:string?
{
  data($xqdoc2html:ZorbaManifest/module[@uri= $moduleUri]/@version)
};

(:~
 : This function embeds some content into XML or XQuery.
 :
 : @param $content the content.
 : @param $type either XML or XQuery are supported.
 : @return A xhtml page.
 :)
declare %private function xqdoc2html:create-xhtml-wrapper(
  $content,
  $type as xs:string)
{
  <html>
  <head>
    <meta content="text/html; charset=UTF-8" http-equiv="content-type" />
    <meta content="public" http-equiv="CACHE-CONTROL" />
    <meta content="-1" http-equiv="Expires" />
    <link rel="stylesheet" type="text/css" href="../styles/main.css" />
    <script type="text/javascript" src="../lib/jquery.cookie.js"></script>
    <script type="text/javascript" src="../lib/shCore.js"></script>
    <script type="text/javascript" src="../lib/shBrushXQuery.js"></script>
    <script type="text/javascript" src="../lib/shBrushXml.js"></script>
    <link type="text/css" rel="stylesheet" href="../styles/shCore.css"/>
    <link type="text/css" rel="stylesheet" href="../styles/shThemeDefault.css"/>
    <link type="text/css" rel="stylesheet" href="../styles/shThemeXQuery.css"/>
    <script type="text/javascript">
      SyntaxHighlighter.all()
    </script>
  </head>
  <body>
  <pre class="brush: {$type};">{$content}</pre>
  </body>
  </html>
};

declare %private %an:sequential function xqdoc2html:copy-schemas(
  $schemas,
  $xqdocXhtmlPath as xs:string
)
{
  for $schema in $schemas
  let $schemaURI := data($schema/xqdoc:uri)
  return
    (: if the schema does not already exists :)
    if(empty($xqdoc2html:schemasCollector/schema[@uri=$schemaURI])) then
    {
      variable $schemaName := concat(xqdoc2html:get-filename($schemaURI), ".html");
      xqdoc2html:collect-schema($schemaURI, $schemaName, $xqdoc2html:schemasCollector);

      variable $schemaContent := fetch:content($schemaURI, "SCHEMA");
      variable $schemaPath := concat($xqdocXhtmlPath,
                                     file:directory-separator(),
                                     "schemas",
                                     file:directory-separator(),
                                     $schemaName);
      file:write($schemaPath,  xqdoc2html:create-xhtml-wrapper($schemaContent,"xml"), $xqdoc2html:serParamXhtml);
    }
    else ();
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
declare %private %an:sequential function xqdoc2html:generate-xqdoc-xhtml(
  $generalLeftMenu,
  $xhtmlRequisitesPath  as xs:string,
  $xqdocXhtmlPath       as xs:string
  ) as xs:string*
{
  variable $modulePath  := fn:concat($xqdocXhtmlPath, file:directory-separator(), $xqdoc2html:moduleFolderName);
  variable $examplesFolderDestination := fn:concat($xqdocXhtmlPath, file:directory-separator(),$xqdoc2html:exampleFolderName);
  file:create-directory($modulePath);
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
       ($moduleUri = "http://www.w3.org/2005/xpath-functions/math") or
       ($moduleUri = "http://www.functx.com/")) then
    {
      (:these modules never change, they have no tests, no external functions, and so on:)
      (:just read the content from the templates folder and compute the left menu:)
      variable $templatesPath := concat($xhtmlRequisitesPath, file:directory-separator(), 'templates');
      variable $xhtmlSource := concat($templatesPath, file:directory-separator(), $xhtmlRelativeFilePath);

      variable $xhtml := xqdoc2html:add-left-menu($generalLeftMenu, $xhtmlSource);
      variable $xhtmlFilePath := fn:concat($xqdocXhtmlPath, file:directory-separator(), $xhtmlRelativeFilePath);
      file:write($xhtmlFilePath, $xhtml, $xqdoc2html:serParamXhtml);

      (: copy the .xq module to the xhtml/modules folder :)
      variable $moduleContent := fetch:content($moduleUri, "MODULE");
      variable $destination := fn:concat($modulePath, file:directory-separator(), pxqdoc:get-filename($moduleUri),".html");
      file:write( $destination,
                xqdoc2html:create-xhtml-wrapper($moduleContent,"xquery"),
                $xqdoc2html:serParamXhtml);
    }
    else
    {
      (: replace the inlined examples with actual XQuery code :)
      variable $examplesPath := xqdoc2html:get-project-root($moduleUri);
      variable $xqdoc2 := xqdoc2html:configure-xml($docNode/xqdoc:xqdoc, $examplesPath, $xqdocXhtmlPath);

      (: copy the examples listed in the .xq file into the xhtml/examples folder :)
      xqdoc2html:copy-examples($xqdoc2, $examplesFolderDestination, $examplesPath);

      (: copy the .xq module to the xhtml/modules folder :)
      variable $moduleContent := fetch:content($moduleUri, "MODULE");
      variable $destination := fn:concat($modulePath, file:directory-separator(), pxqdoc:get-filename($moduleUri),".html");
      file:write( $destination,
                xqdoc2html:create-xhtml-wrapper($moduleContent,"xquery"),
                $xqdoc2html:serParamXhtml);

      (: copy the schemas that are imported by this module :)
      variable $schemaImports := $docNode/xqdoc:xqdoc/xqdoc:imports/xqdoc:import[@type="schema"];
      if(count($schemaImports) ne xs:integer(0)) then
        xqdoc2html:copy-schemas($docNode/xqdoc:xqdoc/xqdoc:imports/xqdoc:import[@type="schema"], $xqdocXhtmlPath);
      else ();

      if($xqdoc2/xqdoc:module/@type = "library") then
      {
        variable $templatePath := fn:concat($xhtmlRequisitesPath, file:directory-separator(),"templates",file:directory-separator(),"main.html");
        variable $xhtml := xqdoc2html:doc($xqdoc2, $generalLeftMenu, $templatePath, $xqdocXhtmlPath);
        variable $xhtmlFilePath := fn:concat($xqdocXhtmlPath, file:directory-separator(), $getFilename,".html");
        file:write($xhtmlFilePath, $xhtml, $xqdoc2html:serParamXhtml);
      }
      else ();
    }
  }
  catch *
  {
    fn:error($err:UE004, fn:concat("FAILED: ", $moduleUri, " Message: ", $werr:description));
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
declare %private %an:sequential function xqdoc2html:configure-xml (
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
declare %private %an:sequential function xqdoc2html:copy-examples(
  $xqdoc,
  $examplesFolderDestination as xs:string,
  $examplePath as xs:string)
{
  (:copy the @examples:)
  {
    variable $noExamples := count($xqdoc/xqdoc:functions/xqdoc:function/xqdoc:comment/xqdoc:custom[@tag="example"]);
    (:if($noExamples ne xs:integer(0)) then
      trace($noExamples,
          " number of examples processed");
    else ();:)
    for $example in $xqdoc/xqdoc:functions/xqdoc:function/xqdoc:comment/xqdoc:custom[@tag="example"]
    let $exampleText := xqdoc2html:get-example-filename($example/text())
    let $exampleDestination := fn:concat($examplesFolderDestination, "/", replace($exampleText,'.xq','.html'))
    return
    {
      variable $exampleSource := fn:concat($examplePath, "/", $example/text());
      if(not(file:is-file($exampleSource))) then
        fn:error($err:UE009, fn:concat("Copy example from <", $exampleSource,"> to <", $exampleDestination, "> failed."))
      else
      try {
        xqdoc2html:copy-example($exampleSource, $exampleDestination, $examplePath)
      } catch *  {
        fn:error($err:UE009, fn:concat("Copy example from <", $exampleSource,"> to <", $exampleDestination, "> failed. Error code: ", $werr:code, " Message: ", $werr:description))
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
declare %private %an:nondeterministic function xqdoc2html:resolve-file-path(
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

declare %private %an:sequential function xqdoc2html:copy-example(
  $exampleSource as xs:string,
  $exampleDestination as xs:string,
  $examplePath as xs:string)
{
  (:file:copy($exampleSource,$exampleDestination) :)
  let $search-queries := fn:concat("rbkt[", file:directory-separator(), file:directory-separator(), "//]Queries")
  let $exampleContent := file:read-text( $exampleSource )
  return
  if (fn:not(fn:matches($exampleSource, "[.]xq$")) or
      fn:not(fn:matches($exampleSource, $search-queries))) then
    file:write( $exampleDestination,
                xqdoc2html:create-xhtml-wrapper($exampleContent,"xquery"),
                $xqdoc2html:serParamXhtml)
  else if (fn:matches($exampleContent, "output", "i")) then
    file:write( $exampleDestination,
                xqdoc2html:create-xhtml-wrapper($exampleContent,"xquery"),
                $xqdoc2html:serParamXhtml)
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
                           xqdoc2html:create-xhtml-wrapper($exampleContent,"xquery"),
                           $xqdoc2html:serParamXhtml);
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
              file:write($exampleDestination,
                         xqdoc2html:create-xhtml-wrapper($exampleContent,"xquery"),
                         $xqdoc2html:serParamXhtml);
            }
          }
          else
          {
            variable $exampleContent := fn:concat($exampleContent, "

:)
");
          file:write($exampleDestination,
                     xqdoc2html:create-xhtml-wrapper($exampleContent,"xquery"),
                     $xqdoc2html:serParamXhtml);
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
            file:write($exampleDestination,
                       xqdoc2html:create-xhtml-wrapper($exampleContent,"xquery"),
                       $xqdoc2html:serParamXhtml);
          }
          else
          {
            fn:error($err:UE008, fn:concat("The example <", $exampleSource,"> does not have expected output. Add the example input and expected output by hand in the example, in a commentary that should also include the word 'output'."));
          }
        }
};

declare %private %an:sequential function xqdoc2html:parse-spec-args(
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
      if(fn:string-length($arg_split) eq 0) then string-join($specLines, " ")
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

declare %private %an:sequential function xqdoc2html:load-expected-results(
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

declare %private %an:sequential function xqdoc2html:parse-spec-results(
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
declare %private function xqdoc2html:contains-external-functions (
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

declare %private function xqdoc2html:add-images(
  $type as xs:string)
{
  let $ZorbaOptAndAnn := "../../html/options_and_annotations.html",
      $xquSpec := "http://www.w3.org/TR/xquery-update-10/#dt-updating-function",
      $xqsSpec := "../../html/scripting_spec.html",
      $xq11Spec := "http://www.w3.org/TR/xquery-11/#FunctionDeclns",
      $xqExternal := "http://www.w3.org/TR/xquery-30/#dt-external-function",
      $imagesPath := "images/"
  return
    <span class="no_underline">
      {if(contains($type, "updating")) then
        <a  href="{$xquSpec}"
            title="updating"
            target="_blank"><img src="{concat($imagesPath, "Updating.gif")}" alt="Updating"/></a>
       else ()}
       {if(contains($type, "sequential")) then
        <a  href="{$xqsSpec}"
            title="sequential"
            target="_blank"><img src="{concat($imagesPath, "Sequential.gif")}" alt="Sequential"/></a>
       else ()}
       {if(contains($type, "nondeterministic ")) then
        <a  href="{$ZorbaOptAndAnn}"
            title="%an:nondeterministic"
            target="_blank"><img src="{concat($imagesPath, "Nondeterministic.gif")}" alt="Nondeterministic"/></a>
       else ()}
       {if(contains($type, "variadic")) then
        <a  title="A function annotated with the http://www.zorba-xquery.com/annotations:variadic annotation is a function of indefinite arity, i.e. one that accepts a variable number of arguments."
            href="{$ZorbaOptAndAnn}"
            target="_blank"><img src="{concat($imagesPath, "Variadic.gif")}" alt="Variadic"/></a>
       else ()}
       {if(contains($type, "streamable")) then
        <a  href="{$ZorbaOptAndAnn}" title="A function annotated with the http://www.zorba-xquery.com/annotations:streamable annotation is
        a function that may return an xs:string item whose content is streamed. Such a string is called a streamable string.
        Such strings have the advantage that their contents doesn't need to be materialized in memory.
        If a function consuming such a string is able to process the string in a streaming fashion,
        this allows for processing of strings with a virtually infinite length.
        However, the disadvantage is that a streamable string can only be consumed exactly once.
        If a streamable string is consumed more than once, an error is raised.
        In order to enable multiple consumers of a streamable string, the string:materialize function can be used
        to materialize the entire contents in an (regular) xs:string item." target="_blank"><img src="{concat($imagesPath, "Streamable.gif")}" alt="Streamable"/></a>
       else ()}
       {if(contains($type, "external")) then
        <a href="{$xqExternal}" title="external" target="_blank"><img src="{concat($imagesPath, "External.gif")}" alt="External"/></a>
       else ()}
    </span>
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
declare %private %an:sequential function xqdoc2html:add-left-menu(
  $menu,
  $templatePath as xs:string) {
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
declare %private %an:sequential function xqdoc2html:doc(
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
declare %private %an:nondeterministic function xqdoc2html:body(
  $xqdoc,
  $xqdocXhtmlPath as xs:string)
{
  (: use only the functions not marked as %private :)
  let $functions := for $function in $xqdoc/xqdoc:functions/xqdoc:function
                    where xqdoc2html:function-is-not-private($function)
                    return $function
  let $moduleUri := xqdoc2html:module-uri($xqdoc)
  let $isZorbaCore as xs:boolean := xqdoc2html:get-is-core($moduleUri)
  let $modulePrefix as xs:string := if(count($functions) ne xs:integer(0)) then
  substring-before($xqdoc/xqdoc:functions/xqdoc:function[1]/xqdoc:name/text(),':') else
  if($xqdoc/xqdoc:variables/xqdoc:variable) then
  substring-before($xqdoc/xqdoc:variables/xqdoc:variable[1]/xqdoc:uri/text(),':') else
  "modNS"
  return
  (<h1>{$moduleUri}{if ($isZorbaCore) then <sup><img src="images/ZCsmall.gif" alt="ZC" title="This module is part of Zorba core."/></sup> else () }</h1>,
    xqdoc2html:module-description($moduleUri, $modulePrefix, $xqdoc/xqdoc:module),
    xqdoc2html:module-resources($xqdocXhtmlPath, xqdoc2html:module-uri($xqdoc)),
    xqdoc2html:module-dependencies($xqdoc),
    xqdoc2html:module-external-specifications($xqdoc/xqdoc:module),
    xqdoc2html:module-namespaces(
      $xqdoc/xqdoc:module/xqdoc:custom[@tag="namespaces"]
    ),
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
declare %private function xqdoc2html:module-description($moduleUri as xs:string, $modulePrefix as xs:string, $module) {
    ( <div class="section"><span id="module_description">Module Description</span></div>,
      <span>Before using any of the functions below please remember to import the module namespace:
      <pre class="brush: xquery;">import module namespace {$modulePrefix} = "{$moduleUri}";</pre>
      </span>,
      {
        if(xqdoc2html:get-is-core($moduleUri)) then () else
        (<span>Please note that this module does not belong to the core of the Zorba XQuery engine. Please check <a href="../../html/downloads.html" target="_blank">this</a> resource about this module import.</span>,<br />,<br />)
      },
     xqdoc2html:description($module/xqdoc:comment),
     xqdoc2html:annotations-module($module/xqdoc:comment),
     if(($moduleUri = "http://www.w3.org/2005/xpath-functions") or
        ($moduleUri = "http://www.w3.org/2005/xpath-functions/math") or
        ($moduleUri = "http://www.functx.com/")) then ()
     else
      (<div class="subsubsection">XQuery version and encoding for this module:</div>,
       <p class="annotationText">xquery version "{$module/xqdoc:comment/xqdoc:custom[@tag='XQuery version']/text()}" encoding "{$module/xqdoc:comment/xqdoc:custom[@tag='encoding']/text()}";</p>)
     ),
     let $modVersion := xqdoc2html:get-module-version($moduleUri)
     return
     if($modVersion = "") then ()
     else
     (<div class="subsubsection">Zorba version for this module:</div>,
      <p>The latest version of this module is <strong>{$modVersion}</strong>. For more information about module versioning in Zorba please check out <a href="../../html/modules_using.html#mod_versioning" target="_blank">this</a> resource.</p>
     )
};


(:~
 : Create the XHTML for all description annotations.
 :
 : @param $comment the part of the XQDoc file holding the annotations.
 : @return the XHTML for the description annotations.
 :)
declare %private function xqdoc2html:description($comment) {
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
  let $annotations := $comment/xqdoc:*[not((local-name(.) = ("description", "param", "return", "error", "deprecated", "see", "project", "custom")))]
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
 : Create the XHTML for the module resources.
 :
 : @param $moduleUri the module URI.
 : @param $indexCollector the modules names part of the left menu.
 : @return the XHTML for the 'Module Resources'.
 :)
declare %private %an:nondeterministic function xqdoc2html:module-resources(
  $xqdocXhtmlPath as xs:string,
  $moduleUri as xs:string)
{
  let $folder := xqdoc2html:get-filename($moduleUri)
  return
    (<div class="section"><span id="module_resources">Module Resources</span></div>,
     <ul>
       <li>the XQuery module can be found <a href="modules/{fn:concat(pxqdoc:get-filename($moduleUri),".html")}" target="_blank">here</a>.</li>
     </ul>)
};

(:~
 : Create the XHTML for the module dependencies (imported modules, schemas).
 :
 : @param $xqdoc the node containing the XQDoc XML.
 : @return the XHTML for the 'Module Dependencies'.
 :)
declare %private function xqdoc2html:module-dependencies(
    $xqdoc) {
  if (fn:count($xqdoc/xqdoc:imports/xqdoc:import) > 0 or
      fn:count($xqdoc/xqdoc:module/xqdoc:comment/xqdoc:custom[@tag="library"]) > 0) then
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
      <li>
        <a href="{fn:concat(xqdoc2html:get-filename($import/xqdoc:uri/text()) ,'.html')}">{string($import/xqdoc:uri/text())}</a></li>
    }
    </ul></p>
  else (),
  if (fn:count($xqdoc/xqdoc:module/xqdoc:comment/xqdoc:custom[@tag="library"]) > 0) then
    <p>External C++ library dependencies:<ul>
      {
      for $library in $xqdoc/xqdoc:module/xqdoc:comment/xqdoc:custom[@tag="library"]
        return
         <li>{$library/node()}</li>
      }
    </ul></p>
  else (),
  if (fn:count($xqdoc/xqdoc:imports//xqdoc:import[@type = "schema"]) > 0) then
    (<p>Imported schemas:<ul>
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
    </ul></p>,
    <p>Please note that the schemas are not automatically imported in the modules that import this module. <br />
    In order to import and use the schemas, please add:
    <pre class="brush: xquery;">
    {
    let $namespaces := $xqdoc/xqdoc:module//xqdoc:custom[@tag = "namespaces"]
    return
    string-join(
    for $import in $xqdoc/xqdoc:imports//xqdoc:import[@type = "schema"]
      return
       concat('import schema namespace ',
              $namespaces//xqdoc:namespace[(@uri = $import/xqdoc:uri/text()) and (@isSchema = "true")]/@prefix,
              ' =  "',
              string($import/xqdoc:uri/text()),'";'),"
")
    }
    </pre></p>)
  else ()
  )
};

(:~
 : Create the items for the Related Documentation
 : ('see' annotations appearing in the module description part).
 :
 : @param $module the node containing the XQDoc XML module.
 : @return the XHTML for the 'Related Documentation'.
 :)
declare %private function xqdoc2html:module-external-specifications($module) {
  if(fn:count($module/xqdoc:comment/xqdoc:*[(local-name(.) = ("see"))]) >0) then
    (<div class="section"><span id="external_specifications">Related Documentation</span></div>,
    <p>For more details please also see:<ul>
    {
      let $annotations := $module/xqdoc:comment/xqdoc:*[(local-name(.) = ("see"))]
      return
        for $annotation in $annotations
        return
          if(fn:count($annotation/node()) eq 1) then
            <li>{xqdoc2html:replace-with-a-html-tag(xs:string($annotation/node()))}</li>
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
declare %private function xqdoc2html:module-variables($variables)
{
  let $noPublicVariables :=
    count(for $variable in $variables/xqdoc:variable
          where (count($variable/xqdoc:annotations/xqdoc:annotation[@localname="private"]) = 0)
          return $variable)
  return
  if($noPublicVariables eq xs:integer(0)) then ()
  else
   (<div class="section"><span id="variables">Variables</span></div>,
    <table class="funclist">
   {
      for $variable in $variables/xqdoc:variable
      let $name := $variable/xqdoc:uri/text()
      let $type := $variable/xqdoc:comment/xqdoc:custom[@tag="type"]/text()
      let $isExternal := $variable/xqdoc:comment/xqdoc:custom[@tag="isExternal"]/text()
      let $an := string-join((for $annotation in $variable/xqdoc:annotations/xqdoc:annotation
                               return data($annotation/@localname),
                               if($isExternal) then "external" else ""," ")," ")

      where (count($variable/xqdoc:annotations/xqdoc:annotation[@localname="private"]) = 0)
      order by $name
      return (<tr>
              <td>{xqdoc2html:add-images($an)}</td>
              <td>${$name}
                  {if(exists($type)) then concat(" as ",$type) else ""}
                  {if(exists($isExternal)) then " external" else ()}<br/>
                  {normalize-space(xqdoc2html:description($variable/xqdoc:comment))}</td>
              </tr>
             )
    }
    </table>)
};

(:~
 : Create the module namespaces XHTML.
 :
 : @param $namespaces the custom node containing the XQDoc XML namespaces.
 : @return the XHTML for the module namespaces.
 :)
declare %private function xqdoc2html:module-namespaces($namespaces)
{
  if($namespaces/xqdoc:namespace) then
    (<div class="section"><span id="variables">Namespaces</span></div>,
    <table class="varlist">
    {
      for $namespace in $namespaces/xqdoc:namespace
      let $prefix := data($namespace/@prefix)
      let $uri := data($namespace/@uri)
      (:where empty($variable/xqdoc:invoked) :)
      order by $prefix
      return (<tr>
              <td>{$prefix}</td>
              <td>{$uri}</td>
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
declare %private function xqdoc2html:module-function-summary($functions)
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
        let $type := replace(normalize-space(substring-after(substring-before($signature, "function"), "declare")),"%",""),
            $isExternal := ends-with($signature, "external"),
            $paramsAndReturn := substring-after($signature,concat(':',$name)),
            $external := if(ends-with($signature,"external")) then "external" else ""
        return
          <tr>
            <td class="type">{xqdoc2html:add-images(concat($type," ",$external))}</td>
            <td>
              <tt>{
                if ($isDeprecated) then
                  <span class="functName"><del><a href="#{$name}-{$param-number}" title="{$shortDescription}">{$name}</a></del></span>
                else
                  <span class="functName"><a href="#{$name}-{$param-number}" title="{$shortDescription}">{$name}</a></span>
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
declare %private function xqdoc2html:split-function-signature($signature as xs:string) {
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
            substring-before($rest, ")")
        (: the return type is specified :)
        else
          $tmp
    (: no parameters :)
    else
      ""
  let $after := substring-after($signature, concat($params, ")"))
  let $parts := fn:tokenize($line1,' ')
  let $line11 := fn:string-join(for $part in $parts return $part, ' ')
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
declare %private %an:nondeterministic function xqdoc2html:functions($functions, $xqdocXhtmlPath) {
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
        }<a href="#function_summary"><img class="floatright" src="images/up.gif" alt="back to 'Function Summary'" title="back to 'Function Summary'"/></a></div>,
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
        xqdoc2html:annotations-author($comment),
        xqdoc2html:annotations-see($comment),
        xqdoc2html:annotations-example($comment, $xqdocXhtmlPath),
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
return
(
  xqdoc2html:add-images(string-join((
  if(contains($lcSignature, 'updating')) then
    'updating' else (),

  if(contains($lcSignature, 'sequential')) then
    'sequential' else (),

  if(contains($lcSignature, 'nondeterministic')) then
    'nondeterministic' else (),

  if(contains($lcSignature, 'non-deterministic')) then
    'nondeterministic' else (),

  if(contains($lcSignature, 'variadic')) then
    'variadic' else (),

  if(contains($lcSignature, 'streamable')) then
    'streamable' else (),
  if(ends-with($signature, 'external')) then
    'external' else ())," ")),

  $name
)
};

(:~
 : Return the function parameters.
 :
 : @param $comment the part of the XQDoc file holding the function parameters.
 : @return the XHTML for the function parameters.
 :)
declare %private function xqdoc2html:function-parameters($comment) {
  let $params := $comment/xqdoc:param
  return
    if (exists($params)) then
      (<div class="subsubsection">Parameters:</div>,
      <ul>
      {for $param in $params return <li>{$param/node()}</li>}
      </ul>)
    else ()
};

(:~
 : Create the XHTML for all function return values.
 :
 : @param $comment the part of the XQDoc file holding the function annotations.
 : @return the XHTML for the function return values.
 :)
declare %private function xqdoc2html:function-return($comment) {
  let $return := $comment/xqdoc:return
  return
    if (exists($return)) then (
      <div class="subsubsection">Returns:</div>,
      <ul><li>{$return/node()}</li></ul>
    ) else ()
};

(:~
 : Return the possible function errors.
 :
 : @param $comment the part of the XQDoc file holding the function errors.
 : @return the XHTML for the function errors.
 :)
declare %private function xqdoc2html:errors($comment) {
  let $errors := $comment/xqdoc:error
  return
    if (exists($errors)) then
      (<div class="subsubsection">Errors:</div>,
      <ul>
      {for $error in $errors return <li>{data($error)}</li>}
      </ul>)
    else ()
};

declare %private function xqdoc2html:annotations-author($comment) {
  let $authors := $comment/xqdoc:*[(local-name(.) = ("author"))]
  return
  if (exists($authors)) then (
      <div class="subsubsection">Author:</div>,
      <p class="annotationText">{string-join(for $author in $authors return $author/node(),', ')}</p>
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
declare %private function xqdoc2html:annotations($comment) {
  let $annotations := $comment/xqdoc:*[not((local-name(.) = ("description", "param", "return", "error", "deprecated", "see", "custom", "author")))]
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

declare %private function xqdoc2html:replace-with-a-html-tag(
  $text as xs:string)
{
 (: this is meant to be used only for the @see tags at this moment :)
 let $containsHttp := starts-with(lower-case($text), "http://"),
     $isModuleURI as xs:boolean := exists($xqdoc2html:ZorbaManifest/module[@uri= $text])
 return
  if($containsHttp) then
  (
    if($isModuleURI) then
      <a href="{concat(xqdoc2html:get-filename($text),'.html')}">{$text}</a>
    else
      <a href="{$text}" target="_blank">{$text}</a>
  )
  else $text
};

(:~
 : This function groups together all the @see annotations.
 :
 : @param $comment the part of the XQDoc file holding the function annotations.
 : @return the XHTML for the function 'see' annotations.
 :)
declare %private function xqdoc2html:annotations-see($comment) {
  let $see := $comment/xqdoc:*[local-name(.) = ("see")]
  return
    if (count($see) = 0) then ()
    else
(: **********************************************************     :)
(: this hack should be replaced with links everywhere in text     :)
(: replace the @see nodes that start with http:// with HTML a tag :)
    (<div class="subsubsection">See:</div>,<ul>
    {
    for $annotation in $see
    return
      if(fn:count($annotation/node()) eq 1) then
        <li>{xqdoc2html:replace-with-a-html-tag(xs:string($annotation/node()))}</li>
      else
        <li>{$annotation/node()}</li>
    }
    </ul>
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
declare %private %an:nondeterministic function xqdoc2html:annotations-example($comment, $xqdocXhtmlPath) {
  let $example := $comment//xqdoc:custom[@tag="example"]
  return
    if (count($example) = 0) then ()
    else
    (<div class="subsubsection">Examples:</div>,<ul>
    {for $annotation in $example
    let $exampleFileName := fn:concat("examples", file:directory-separator(),replace(xqdoc2html:get-example-filename($annotation/node()),".xq",".html"))
    return
      if(file:exists(fn:concat($xqdocXhtmlPath, file:directory-separator(), $exampleFileName))) then
        <li><a href="{$exampleFileName}" target="_blank">{xqdoc2html:get-example-filename-link($annotation/node())}</a></li>
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
declare %private function xqdoc2html:generate-function-index()
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
                  }{$paramsAndReturn}<br /><span class="padding">Module Namespace: <a href="{$file}">{$moduleUri}</a></span></tt></div>
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
declare %private %an:sequential function xqdoc2html:generate-function-index-xhtml(
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

declare %private %an:sequential function xqdoc2html:collect-entry (
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

declare %private %an:sequential function xqdoc2html:collect-menu-entries()
{
  for $docNode in dml:collection(xs:QName("xqdoc2html:collection"))
      let $module := $docNode/xqdoc:xqdoc/xqdoc:module,
          $lModuleProject := $module/xqdoc:comment/xqdoc:custom[@tag="project"]/text(),
          $lModuleUri     := $module/xqdoc:uri/text(),
          $lXHTMLFileName := pxqdoc:get-filename($lModuleUri),
          $lPureXquery    := not(xqdoc2html:contains-external-functions($docNode/xqdoc:xqdoc)),
          $lTmp := substring-after($lModuleUri,'http://'),
          $lTmpTok := tokenize($lTmp,'/'),
          $lTmp2 := if(ends-with($lTmp,'/')) then substring($lTmp,1,string-length($lTmp)-1) else string-join(xqdoc2html:value-except($lTmpTok,$lTmpTok[last()]),'/'),
          $lModuleName    := if(ends-with($lModuleUri,'/')) then $lTmpTok[last()-1] else $lTmpTok[last()],
          $structure      := if(exists($lModuleProject)) then $lModuleProject else $lTmp2
  order by $lModuleProject, $lModuleUri
    return
      xqdoc2html:collect-entry( $lXHTMLFileName,
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
declare %private %an:sequential function xqdoc2html:create-module-helper(
  $table,
  $category as xs:string,
  $currentCategory as xs:string
  )
{
  {
    (:insert nodes <li><span class="leftMenu">{$category}</span><ul>:)
    insert nodes <li><span>{$category}</span><ul>
    {
      for $entry in $xqdoc2html:menuEntries/entry
      let $isZorbaCore as xs:boolean := xqdoc2html:get-is-core(data($entry/@moduleURI))
      order by $entry/@structure
      where ($entry/@structure eq $currentCategory)
      return
        <li>
          <a href="{data($entry/@href)}.html" title="{data($entry/@moduleURI)}">{data($entry/@name)}</a>
          {
            if(xs:boolean(data($entry/@pureXQuery))) then ()
            else
              <sup><a href="http://www.w3.org/TR/xquery-30/#dt-external-function"
              target="_blank" title="There are external functions (either private or public) declared in this module.">(E)</a></sup>
          }
          {
            if($isZorbaCore) then
              <sup><img src="images/ZCsmall.gif" alt="ZC" title="This module is part of Zorba core."/></sup>
            else ()
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
declare %private %an:sequential function xqdoc2html:create-module-table-rec(
  $level1 as xs:string*,
  $leveln as xs:string*,
  $curentCat as xs:string,
  $table,
  $mustOrder as xs:boolean) {
  if(empty($leveln)) then ()
  else
    if($mustOrder) then
      for $cat in $leveln
      order by lower-case($cat)
      return {
        variable $lCurentCat := if($curentCat eq "") then $cat else concat($curentCat,'/',$cat);
        xqdoc2html:create-module-helper($table, $cat, $lCurentCat);
        xqdoc2html:create-module-table-rec($level1, xqdoc2html:get-distinct-children($level1,$lCurentCat), $lCurentCat,$table/li[fn:last()]/ul, fn:true())
      }
    else
      for $cat in $leveln
      return {
        variable $lCurentCat := if($curentCat eq "") then $cat else concat($curentCat,'/',$cat);
        xqdoc2html:create-module-helper($table, $cat, $lCurentCat);
        xqdoc2html:create-module-table-rec($level1, xqdoc2html:get-distinct-children($level1,$lCurentCat), $lCurentCat,$table/li[fn:last()]/ul, fn:true())
      }
};


declare %private function xqdoc2html:order-level1-entries
($entries as xs:string*) as xs:string*
{
 (: show first the items in the $xqdoc2html:level1Weight that were also found in the modules :)
 let $defined := for $str in $xqdoc2html:level1Weight return xqdoc2html:value-intersect($str, $entries)

 (: if there are any other level 1 items found in the modules, show them also ordered alphabetically:)
 let $undefined := xqdoc2html:value-except($entries, $defined)

 return ($defined, for $str in $undefined order by $str return $str)
};

(:~
 : This function creates the categories in the menu.
 :
 : @param $leftMenu the menu.
 : @param $root the root.
 : @param $moduleUri module URI.
 : @return $root after the subcategories were added to it.
 :)
declare %private %an:sequential function xqdoc2html:create-module-table(
  $level1 as xs:string*,
  $root)
{
  {
    variable $leveln := distinct-values(for $str in $level1 return tokenize($str,'/')[1]);

    xqdoc2html:create-module-table-rec($level1, xqdoc2html:order-level1-entries($leveln), "", $root, fn:false());

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
declare %private function xqdoc2html:create-left-menu()
{
  <ul>
    <li><a href="index.html">All Modules</a></li>
    <li><a href="{$xqdoc2html:functionIndexPageName}">All Functions</a></li>
  </ul>
};

(:
declare %private %an:sequential function xqdoc2html:create-specialized-left-menu(
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
      <span class="leftmenu_active">{$node/a/text()}
      {
        if($lPureXquery) then ()
        else
          <sup><span class="superscript"><a href="http://www.w3.org/TR/xquery-30/#dt-external-function"
          target="_blank" title="There are external functions (either private or public) declared in this module.">(E)</a></span></sup>
      }</span>
      {
        if($isZorbaCore) then
          <sup><img src="images/ZCsmall.gif" alt="ZC" title="This module is part of Zorba core."/></sup>
        else ()
      }</li>;
  }

  $generalLeftMenu
};
:)

(:~
 : This function reads, updates and returns the new index.html.
 :
 : @param $templatePath the path to the 'main.html' template.
 : @param $menu the menu.
 : @param $modules the modules.
 : @param $zorbaVersion Zorba version.
 : @return The content of the new index.html.
 :)
declare %private %an:sequential function xqdoc2html:generate-index-html(
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
              <p>This document contains a list of all the <strong>core</strong> and <strong>non core</strong> Zorba modules.</p>,
              <p>Please check out <a href="../../html/modules_top.html">Modules in Zorba</a> documentation page.</p>,
              <p>The <strong>core</strong> Zorba modules are annotated below with this small image: <sup><img src="images/ZCsmall.gif" alt="ZC" title="This module is part of Zorba core."/></sup>.</p>,
              <p>The superscript (E) denotes modules that have external functions. Those are not portable to other XQuery processors.</p>,
              <p>Please send us comments in case you would like to suggest us adding a particular XQuery module, or if you would like to donate an existing third party XQuery module.</p>,
              $modules)
            as last into $right_content;
          else
            ();

        $indexHtmlDoc
    }
};

