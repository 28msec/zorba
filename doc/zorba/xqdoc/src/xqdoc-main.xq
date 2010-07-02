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
 : This variable contains categories in the left menu
 :)
declare variable $moduleCategories as xs:string* := (
'http://expath.org/ns',
'http://www.zorba-xquery.com/modules',
'http://www.w3.org/2005'
);

declare variable $menu := <ul class="treeview" id="documentation"><span class="leftMenu"><strong>XQuery Libraries</strong></span></ul>;

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

declare variable $stepBacks as xs:string := "../../../../../../../../../../../../../../../../../../../../";

(:~
 : This variable contains the to the index.html main page
 :)
declare variable $indexHtmlPath as xs:string external;

declare variable $indexCollector := <modules/>;

declare function local:getFileName($moduleURI as xs:string) as xs:string
{
    replace(
        replace($moduleURI, "/", "_"),
        "http:__",
        ""
    )
};

declare sequential function local:clearFolder($folderPath as xs:string, $pattern as xs:string) as xs:string*
{
  if(fn:not(file:exists($folderPath))) then
    return
  else
    for $file in file:files($folderPath, $pattern, fn:true())
    let $filePath := fn:concat($folderPath, file:path-separator(), $file)
    return
      try {
        file:remove($filePath);
        concat("
  SUCCESS: ", $filePath);
      } catch * ($error_code) {
        concat("
  FAILED: ", $filePath)
      }
};

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
  let $moduleDoc := $xqdoc/xqdoc:module
  let $moduleName := $moduleDoc/xqdoc:name
  let $moduleUri := $moduleDoc/xqdoc:uri
  return
    try {
      file:mkdirs($xqdocXmlPath, false());
      let $x := fn:count(file:files($xqdocXmlPath, "\.xml$", fn:true())) + 1
      let $xqdocFileName := fn:concat($xqdocXmlPath, file:path-separator(), local:getFileName($moduleUri), ".xml")
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
 : @param $indexPath path to the XHTML index page.
 :)
declare sequential function local:generateXQDocXhtml($indexPath as xs:string) as xs:string* 
{
  let $indexHtmlDoc := file:read-xml($indexPath)
  return
  for $file in file:files($xqdocXmlPath, "\.xml$", fn:true())
  let $stepsFromIndex := fn:count(fn:tokenize($file, fn:concat("\", file:path-separator()))) - 2
  let $xmlFilePath := concat($xqdocXmlPath, file:path-separator(), $file)
  let $xhtmlFilePath := concat($xqdocXhtmlPath, file:path-separator(), fn:replace($file, "\.xml$", ".html"))
  let $relativeXhtmlFilePath := fn:replace($file, "\.xml$", ".html")
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
      let $menu := <ul class="treeview" id="documentation"><span class="leftMenu"><strong>XQuery Libraries</strong></span></ul> 
      let $menu := local:createLeftMenu($menu, $moduleUri)
      let $xhtml := xqdg:doc($xqdoc, $menu)
      return block {
        file:mkdirs($xhtmlFileDir, false());

        local:configure-xhtml($xhtml, $stepsFromIndex);

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
 : This function gathers the names of the XQDoc XHTML pages for all the XQDoc XML
 : documents found in $xqdocXmlPath. The hierarchy is preserved. 
 :)
declare sequential function local:gatherModules()
{
  for $file in file:files($xqdocXmlPath, "\.xml$", fn:true())
  let $xmlFilePath := concat($xqdocXmlPath, file:path-separator(), $file)
  let $relativeXhtmlFilePath := fn:replace($file, "\.xml$", ".html")
  return
  try {
      let $xqdoc := local:removeInternalFunctionality(file:read-xml($xmlFilePath)/xqdoc:xqdoc)
      let $moduleDoc := $xqdoc/xqdoc:module
      let $moduleUri := $moduleDoc/xqdoc:uri
      return block {
        local:collectModule($moduleDoc, $relativeXhtmlFilePath);
        concat("
SUCCESS: ", $moduleUri, " (", $xmlFilePath, ")");
      }
    } catch * ($error_code) {
      concat("
FAILED: ", $xmlFilePath)
    }  
};

declare sequential function local:collectModule ($module, $relativeFileName as xs:string) {
    let $moduleName := $module/xqdoc:name,
        $moduleUri := $module/xqdoc:uri
    return
        insert node <module uri="{$moduleUri/text()}" file="{$relativeFileName}" /> as last into $indexCollector;
    ();
};    

(:~
 : This function returns the left menu needed in the index.html and also all the XHTML module pages.
 :)
declare sequential function local:createLeftMenu($menu, $moduleUri)
{
  for $cat in $moduleCategories
  return block {
    if(fn:index-of($moduleCategories, $cat) = fn:count($moduleCategories)) then
      insert nodes <li class='expandable lastExpandable'><div class='hitarea expandable-hitarea'>{' '}</div>
      <span class='leftMenu'>{$cat}</span>
          <ul style='display: none;'>
          {
          for $module in $indexCollector/module
          order by fn:data($module/@uri)
          return block {
            if(fn:starts-with(fn:string($module/@uri),$cat) and fn:not($module/@uri = $moduleUri)) then
              <li><a href="{$module/@file}">{fn:substring-after(data($module/@uri),fn:concat($cat,'/'))}</a></li>
            else if(fn:starts-with(fn:string($module/@uri),$cat) and ($module/@uri = $moduleUri)) then
              <li><span class="leftmenu_active">{fn:substring-after(data($module/@uri),fn:concat($cat,'/'))}</span></li>  
            else ()
            };
          }
          </ul></li> 
      as last into $menu
    else
      insert nodes <li class='expandable'><div class="hitarea expandable-hitarea">{' '}</div>
      <span class='leftMenu'>{$cat}</span>
          <ul style='display: none;'>
          {
          for $module in $indexCollector/module
          order by fn:data($module/@uri)
          return block {
            if(fn:starts-with(fn:string($module/@uri),$cat) and fn:not($module/@uri = $moduleUri)) then
              <li><a href="{$module/@file}">{fn:substring-after(data($module/@uri),fn:concat($cat,'/'))}</a></li>
            else if(fn:starts-with(fn:string($module/@uri),$cat) and ($module/@uri = $moduleUri)) then
              <li><span class="leftmenu_active">{fn:substring-after(data($module/@uri),fn:concat($cat,'/'))}</span></li>  
            else ()
            };
          }
          </ul></li> 
      as last into $menu
  };

  $menu;
};

declare sequential function local:getFilePath ($filename as xs:string) as xs:string*
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

declare function local:get-path-to-index ($stepsBack) as xs:string 
{
  fn:substring($stepBacks, 1, 3 * $stepsBack)
};


declare sequential function local:configure-xhtml ($xhtml, $stepsFromIndex as xs:integer) 
{
  let $pathToIndex := local:get-path-to-index($stepsFromIndex)
  return
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
      $xqsSpec := "http://www.w3.org/TR/xquery-sx-10/#dt-sequential-function",
      $xq11Spec := "http://www.w3.org/TR/xquery-11/#FunctionDeclns"
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
    else if (matches($type, "nondeterministic")) then
      replace node $typeTd/text() with
        <a href="{$xq11Spec}" title="{$type}" target="_blank"><img src="{concat($imagesPath, "N.gif")}" /></a>
    else ();
  };
  
  $xhtml;
};

declare function local:createModuleTable() {
  <ul>
  {
    for $cat in $moduleCategories
    return 
      (
        <li> { $cat }
          <ul>
          {
            for $module in $indexCollector/module
            order by fn:data($module/@uri)
            return
              if (fn:starts-with(fn:string($module/@uri), $cat))
              then
                <li><a href="{$module/@file}">{fn:substring-after(data($module/@uri),fn:concat($cat,'/'))}</a></li>
              else ()
          }
          </ul>
        </li>
      )
   }
   </ul>
};


(:~
 : This function reads, updates and returns the new index.html.
 :
 : @param $indexPath Where to search for XML XQDoc documents recursively.
 : @return The content of the new index.html.
 :)
declare sequential function local:generateIndexHtml($indexPath as xs:string, $menu, $modules) as document-node() {
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

(: generate the XQDoc XML for all the modules :)
if (file:mkdirs($xqdocXmlPath, false())) then
(
  local:clearFolder($xqdocXmlPath,"\.xml$"),
  local:generateXQDocXml()
)
else
  error()
;

(: generate the XQDoc XHTML for all the modules :)
let $absoluteXhtmlDir := concat($xqdocBuildPath, "/xhtml")
return
if (file:mkdirs($absoluteXhtmlDir, false())) then
(
  local:clearFolder($xqdocXhtmlPath,"xqdoc\.html$"),
  local:gatherModules(),
  local:generateXQDocXhtml($indexHtmlPath)
)
else
  error()
;

let $menu := <ul class="treeview" id="documentation">
               <span class="leftMenu"><strong>XQuery Libraries</strong>
               </span>
             </ul> 
let $menu := local:createLeftMenu($menu, "index.html")
let $modules := local:createModuleTable()
let $doc := local:generateIndexHtml($indexHtmlPath, $menu, $modules)
return local:configure-xhtml($doc/*:html, 0)
;
