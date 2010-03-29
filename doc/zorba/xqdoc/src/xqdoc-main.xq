import module namespace file = "http://www.zorba-xquery.com/modules/file";
import module namespace xqd = "http://www.zorba-xquery.com/modules/xqdoc";

import module namespace xqdg = "http://www.zorba-xquery.com/modules/internal/xqdoc-xhtml" at "xqdoc-xhtml.xq";

import schema namespace xqdoc = "http://www.xqdoc.org/1.0" at "xqdoc-1.0.xsd";

declare copy-namespaces preserve, inherit;

(:~
 : This variable contains the relative paths to directories that contain
 : example code fragments that are included.
 :)
declare variable $examplePath as xs:string* := (
    'test/rbkt/Queries/zorba',
    'test/update/Queries',
    'test/rbkt/ExpQueryResults/zorba',
    'test/update/ExpectedTestResults'
);

(:~
 : This variable contains the modules directory path in the source directory.
 :)
declare variable $modulesPath as xs:string external;

(:~
 : This variable contains the path where to generate the XQDoc.
 :)
declare variable $xqdocBuildPath as xs:string external;

(:~
 : This variable points to where the generated XML must be saved.
 :)
declare variable $xqdocXmlPath as xs:string := fn:concat($xqdocBuildPath, file:path-separator(), "xml");

(:~
 : This variable points to where the generated XHTML must be saved.
 :)
declare variable $xqdocXhtmlPath as xs:string := fn:concat($xqdocBuildPath, file:path-separator(), "xhtml");

(:~
 : This variable points to the CSS file to use when generating the XHTML.
 : The path is relative to the taget path of the index.html.
 :)
declare variable $cssFileName as xs:string external;

declare variable $stepBacks as xs:string := "../../../../../../../../../../../../../../../../../../../../";

(:~
 : This variable contains the to the index.html main page
 :)
declare variable $indexHtmlPath as xs:string external;

declare variable $indexCollector := <modules/>;

(:~
 : This function generates the XQDoc XML for all the modules found in $modulesPath
 : and writes the resulting XML documents in $targetPath. The hierarchy is preserved. 
 :
 : @param $modulePath where to search for modules recursively.
 : @param $targetPath where to generate the XQDoc XML documents.
 : @return The function returns a string sequence with a status messge for each
 :         module processed.
 :)
declare sequential function local:generateXQDocXml() as xs:string*
{
  for $filedirs in tokenize($modulesPath, ";")
  for $file in file:files($filedirs, "\.xq$", fn:true())
  let $filePath := fn:concat($filedirs, file:path-separator(), $file)
  let $xqdoc := xqd:xqdoc(file:path-to-uri($filePath))
  let $moduleDoc := $xqdoc/xqdoc:xqdoc/xqdoc:module
  let $moduleName := $moduleDoc/xqdoc:name
  let $moduleUri := $moduleDoc/xqdoc:uri
  let $xqdocFileDir := fn:concat($xqdocXmlPath, file:path-separator(), $file)
  let $xqdocFileName := fn:concat($xqdocFileDir, file:path-separator(), "xqdoc.xml")
  return
    try {
      file:mkdirs($xqdocFileDir, false());
      file:write($xqdocFileName, $xqdoc, <s method="xml" indent="yes" />/@*);
      concat("
SUCCESS: ", $moduleUri, " (", $xqdocFileName, ")");
    } catch * ($error_code) {
      concat("
FAILED: ", $moduleUri, " (", $xqdocFileName, ")")
    }
};


(:~
 : This function removes the internal functionality from an XQDoc XML node.
 :
 : @param $xqdoc The XQDdoc XML node to remove the functionality from.
 : @return The xqdoc node without the internal functionality.
 :)
declare sequential function local:removeInternalFunctionality($xqdoc as node()) as node() {
  delete node $xqdoc/xqdoc:functions/xqdoc:function[fn:starts-with(fn:data(xqdoc:comment/xqdoc:description), "Helper function")];
  $xqdoc; 
};

(:~
 : This function generates the XQDoc XHTML pages for all the XQDoc XML
 : documents found in $xqdocPath and writes the resulting pages to in
 : $targetPath. The hierarchy is preserved. 
 :
 : @param $xqdocPath where to search for XML XQDoc documents recursively.
 : @param $targetPath where to generate the XQDoc XHTML pages.
 :)
declare sequential function local:generateXQDocXhtml() as xs:string* 
{
  for $file in file:files($xqdocXmlPath, "\.xml$", fn:true())
  let $stepsFromIndex := fn:count(fn:tokenize($file, fn:concat("\", file:path-separator()))) - 2
  let $xmlFilePath := concat($xqdocXmlPath, file:path-separator(), $file)
  let $xhtmlFilePath := concat($xqdocXhtmlPath, file:path-separator(), fn:replace($file, "xq.xqdoc\.xml", "html"))
  let $relativeXhtmlFilePath := fn:replace($file, "xq.xqdoc\.xml", "html")
  let $xhtmlFileDir := 
    let $segments := fn:tokenize($xhtmlFilePath, fn:concat("\", file:path-separator()))
    let $lastSegm := $segments[fn:count($segments)] 
    return fn:substring-before($xhtmlFilePath, $lastSegm)
  return
    try {
      let $xqdoc := local:removeInternalFunctionality(file:read-xml($xmlFilePath)/xqdoc:xqdoc)
      let $moduleDoc := $xqdoc/xqdoc:module
      let $moduleName := $moduleDoc/xqdoc:name
      let $moduleUri := $moduleDoc/xqdoc:uri
      let $xhtml := xqdg:doc($xqdoc)
      return block {
        file:mkdirs($xhtmlFileDir, false());

        local:configure-xhtml($xhtml, $stepsFromIndex);

        file:write($xhtmlFilePath, $xhtml, <s method="xhtml" indent="yes" />/@*);
        
        (: This will remember the generated modules for the index.html :)
        local:collectModule($moduleDoc, $relativeXhtmlFilePath);

        concat("
SUCCESS: ", $moduleUri, " (", $xhtmlFilePath, ")");
      }
    } catch * ($error_code) {
      concat("
FAILED: ", $xhtmlFilePath)
    }
};

declare sequential function local:collectModule ($module, $relativeFileName as xs:string) {
    let $moduleName := $module/xqdoc:name,
        $moduleUri := $module/xqdoc:uri
    return
        insert node <module uri="{$moduleUri/text()}" file="{$relativeFileName}" /> as last into $indexCollector;
    ();
};    

declare function local:getFilePath ($filename as xs:string) as xs:string*
{
  let $zorbaPath := replace($modulesPath,"/modules","")
  for $relPath in $examplePath
  let $path := concat($zorbaPath,'/',$relPath)
  let $test := file:files($path,concat("^",$filename,"$"),fn:true())[1]
  return
  if (fn:exists($test)) then
    $test
  else 
    ()
};

declare function local:get-path-to-index ($stepsBack) as xs:string {
  fn:substring($stepBacks, 1, 3 * $stepsBack)
};


declare sequential function local:configure-xhtml ($xhtml, $stepsFromIndex as xs:integer) {
  (: add a stylesheet :)
  let $pathToIndex := local:get-path-to-index($stepsFromIndex)
  let $cssPath := concat($pathToIndex, $cssFileName)
  return    
    replace value of node $xhtml/*:head/*:link/@href with $cssPath
  ;    

  (: replace the <test> nodes with eiter links to the actual files or inline the actual files based on the 'type' attribute value :)
  for $file in $xhtml//*:include
  let $type := $file/@type
  let $path := local:getFilePath($file/text())
  let $read_text := file:read-text($path)
  return block {
  (: at the moment there is no way to ship the files defined as links with the packages/installers
    if (matches($type, "link")) then 
      replace node $file with <a href="{$path}">{$path}</a> 
    else :)
    if (matches($type, "inline")) then
      replace node $file with
        if (fn:exists($path)) then
          <pre> {$path}:<br />
          <pre class="fragment">{$read_text}</pre>
          </pre>
        else
          <pre class="fragment">No example matching pattern '{$file/text()}' was found. Please update 'examplePath' variable.</pre>
        else () 
  };

  (: replace the function type description with images :)
  let $xquSpec := "http://www.w3.org/TR/xquery-update-10/",
      $xqsSpec := "http://www.w3.org/TR/xquery-sx-10/#dt-sequential-function"
  let $pathToIndex := local:get-path-to-index($stepsFromIndex)
  let $imagesPath := concat($pathToIndex, "images/")
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
    else ();
  };

  $xhtml;
};


(:~
 : This function reads, updates and returns the new index.html.
 :
 : @param $xqdocPath Where to search for XML XQDoc documents recursively.
 : @return The content of the new index.html.
 :)
declare sequential function local:generateIndexHtml($indexPath as xs:string) as document-node() {
    let $indexHtmlDoc := file:read-xml($indexPath)
    return block {
        insert nodes
            for $module in $indexCollector/module
            order by fn:data($module/@uri)
            return
                (<a href="{$module/@file}">{data($module/@uri)}</a>, <br />)
        as last into $indexHtmlDoc/*:html/*:body;
        
        $indexHtmlDoc;
    }
};

(: generate the XQDoc XML for all the modules :)
if (file:mkdirs($xqdocXmlPath, false())) then
  local:generateXQDocXml()
else
  error()
;

(: generate the XQDoc XHTML for all the modules :)
let $absoluteXhtmlDir := concat($xqdocBuildPath, "/xhtml")
return
if (file:mkdirs($absoluteXhtmlDir, false())) then
  local:generateXQDocXhtml()
else
  error()
;

let $doc := local:generateIndexHtml($indexHtmlPath)
return local:configure-xhtml($doc/*:html, 0)
;
