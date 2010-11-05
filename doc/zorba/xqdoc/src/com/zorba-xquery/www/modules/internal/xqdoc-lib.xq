module namespace doc2html = "http://www.zorba-xquery.com/modules/internal/xqdoc-lib";

import module namespace file = "http://www.zorba-xquery.com/modules/file";
import module namespace xqd = "http://www.zorba-xquery.com/modules/xqdoc";

import module namespace xqdg = "http://www.zorba-xquery.com/modules/internal/xqdoc-xhtml";

import schema namespace xqdoc = "http://www.xqdoc.org/1.0";


declare copy-namespaces preserve, inherit;

(:~
 : This variable contains the relative paths to directories that contain
 : example code fragments that are included.
 :)
declare variable $doc2html:examplePath as xs:string* := (
    'test/rbkt/Queries/zorba',
    'test/update/Queries',
    'test/rbkt/ExpQueryResults/zorba',
    'test/update/ExpectedTestResults'
);

declare variable $doc2html:stepBacks as xs:string := "../../../../../../../../../../../../../../../../../../../../";

(:~
 : This variable contains all the modules names part of the left menu
 :)
declare variable $doc2html:indexCollector := <modules/>;

(:~
 : This variable contains all the schemas imported by the modules
 :)
declare variable $doc2html:schemasCollector := <schemas/>;

(:~
 : This variable contains all the functions from all imported modules
 :)
declare variable $doc2html:functionsCollector := <functions/>;

(:~
 : This variable contains the links appearing in the first part of the left menu
 : of every XHTML page
 :)
declare variable $doc2html:externalLinks :=   
  <links>
    <a href="http://www.zorba-xquery.com/index.php/tutorials/" 
       title="Tutorials" target="_blank">Tutorials</a>
    <a href="http://experimental.zorba-xquery.org/" 
       title="Get started with XQuery using Zorba"
       target="_blank">Experiment XQuery with Zorba</a>   
  </links>;


declare function doc2html:getFileName($moduleURI as xs:string) as xs:string
{
    replace(
        replace($moduleURI, "/", "_"),
        "http:__",
        ""
    )
};

declare sequential function doc2html:clearFolder($folderPath as xs:string, $pattern as xs:string) as xs:string*
{
  if(fn:not(file:exists($folderPath))) then
    ""
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
 : @param $xqdocXmlPath where to generate the XQDoc XML documents.
 : @return The function returns a string sequence with a status messge for each
 :         module processed.
 :)
declare sequential function doc2html:generateXQDocXml(
  $modulesPath as xs:string, $xqdocXmlPath as xs:string
) as xs:string* {
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
      let $xqdocFileName := fn:concat($xqdocXmlPath, file:path-separator(), doc2html:getFileName($moduleUri), ".xml")
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
declare sequential function doc2html:removeInternalFunctionality($xqdoc as node()) as node() {
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
declare sequential function doc2html:generateXQDocXhtml(
  $indexPath      as xs:string, $xqdocXmlPath   as xs:string,
  $xqdocXhtmlPath as xs:string, $leftMenu as element(menu),
  $modulesPath    as xs:string, $functionIndexPageName as xs:string
) as xs:string* {
  let $indexHtmlDoc := file:read-xml($indexPath)
  return
  for $file in file:files($xqdocXmlPath, "\.xml$", fn:true())
  let $stepsFromIndex := fn:count(fn:tokenize($file, fn:concat("\", file:path-separator()))) - 2
  let $xmlFilePath := concat($xqdocXmlPath, file:path-separator(), $file)
  let $xhtmlFilePath := concat($xqdocXhtmlPath, file:path-separator(), fn:replace($file, "\.xml$", ".html"))
  let $xhtmlFileDir := 
    let $segments := fn:tokenize($xhtmlFilePath, fn:concat("\", file:path-separator()))
    let $lastSegm := $segments[fn:count($segments)] 
    return fn:substring-before($xhtmlFilePath, $lastSegm)
  return
    try {
      let $xqdoc := doc2html:removeInternalFunctionality(file:read-xml($xmlFilePath)/xqdoc:xqdoc)
      let $moduleDoc := $xqdoc/xqdoc:module
      let $moduleName := $moduleDoc/xqdoc:name
      let $moduleUri := $moduleDoc/xqdoc:uri
      let $menu := <ul id="documentation">
      <span><a href="index.html">{string($leftMenu/@title)}</a></span>
      <li><a href="{$functionIndexPageName}">Function Index</a></li>
      {
        for $link in $doc2html:externalLinks//a
        return
          <li>{$link}</li>
      }      
      </ul>
      let $menu := doc2html:createModuleTable($leftMenu, $menu, $moduleUri)
      let $xhtml := xqdg:doc($xqdoc, $menu, $doc2html:indexCollector, $doc2html:schemasCollector)
      return block {
        file:mkdirs($xhtmlFileDir, false());

        doc2html:configure-xhtml($xhtml, $stepsFromIndex, $modulesPath);

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
 : This function generates the XQDoc index function page and writes it to disk 
 :)
declare sequential function doc2html:generateFunctionIndexXhtml(
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
    {doc2html:formatFunctions()}
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

declare sequential function doc2html:gatherSchemas(
  $modulesPath as xs:string) as xs:string* {
  
  for $filedirs in tokenize($modulesPath, ";")
  for $file in file:files($filedirs, "\.xsd$", fn:true())
  let $xsdFilePath := concat($modulesPath, file:path-separator(), $file)
  return
    try {
      let $xqdoc := file:read-xml($xsdFilePath)
      let $xsdUri := $xqdoc/xs:schema/@targetNamespace
      return block {
          doc2html:collectModule($xsdUri, $xsdFilePath, $doc2html:schemasCollector);
          concat("
  SUCCESS: ", $xsdUri, " (", $xsdFilePath, ")");
        }
      } catch * ($error_code) {
        concat("
  FAILED: ", $xsdFilePath)
      }  
};

(:~
 : This function gathers the names of the XQDoc XHTML pages for all the XQDoc XML
 : documents found in $xqdocXmlPath. The hierarchy is preserved. 
 :)
declare sequential function doc2html:gatherModules(
  $xqdocXmlPath as xs:string
){
  for $file in file:files($xqdocXmlPath, "\.xml$", fn:true())
  let $xmlFilePath := concat($xqdocXmlPath, file:path-separator(), $file)
  let $xhtmlRelativeFilePath := fn:replace($file, "\.xml$", ".html")
  let $xhtmlRelativeFilePathSlash := fn:replace($xhtmlRelativeFilePath, fn:concat("\", file:path-separator()), "/")
  return
  try {
      let $xqdoc := doc2html:removeInternalFunctionality(file:read-xml($xmlFilePath)/xqdoc:xqdoc)
      let $moduleDoc := $xqdoc/xqdoc:module
      let $moduleUri := $moduleDoc/xqdoc:uri
      return if($moduleDoc/@type = "library") then 
        block {
          doc2html:collectModule($moduleDoc, $xhtmlRelativeFilePath, $doc2html:indexCollector);
          
          doc2html:collectFunctions($xqdoc, $xhtmlRelativeFilePath, $doc2html:functionsCollector);
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

declare sequential function doc2html:collectModule ($moduleDoc, $relativeFileName as xs:string, $collector) {
insert node <module uri="{$moduleDoc/xqdoc:uri/text()}" file="{$relativeFileName}" /> as last into $collector;
};

declare sequential function doc2html:collectFunctions ($xqdoc, $relativeFileName as xs:string, $collector) {
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

declare function doc2html:formatFunctions(){
<div id="level1"><span class="index">
{
  let $alphabet := ("A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z")
  let $letters := distinct-values(
                  for $function in $doc2html:functionsCollector//function 
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
      ( <h2><a name="{$letter}">{$letter}</a></h2>,
        <hr />,     
        <table class="funclist">
          {
          for $func in $doc2html:functionsCollector//function
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
        </table>,
        
        <div id="allignright">
          <a href="#module_description" title="Back to the Index">'Index'</a>
        </div>     
     )
     )
}
</span>
</div>
};

declare sequential function doc2html:getFilePath (
  $filename as xs:string, $modulesPath as xs:string
) as xs:string* {
  let $zorbaPath := replace($modulesPath,"/modules","")
  for $relPath in $doc2html:examplePath
  let $path := concat($zorbaPath,'/',$relPath)
  let $test := file:files($path,concat("^",$filename,"$"),fn:true())[1]
  return
  if (fn:exists($test)) then
    $test
  else 
    ()
};

declare function doc2html:get-path-to-index ($stepsBack) as xs:string 
{
  (: Error prone: stepsBack > stepBacks :)
  fn:substring($doc2html:stepBacks, 1, 3 * $stepsBack)
};


declare sequential function doc2html:configure-xhtml (
  $xhtml, $stepsFromIndex as xs:integer,
  $modulesPath as xs:string 
) {
  let $pathToIndex := doc2html:get-path-to-index($stepsFromIndex)
  return
  (: replace the <test> nodes with eiter links to the actual files or inline the actual files based on the 'type' attribute value :)
  for $file in $xhtml//*:include
  let $type := $file/@type
  let $path := doc2html:getFilePath($file/text(), $modulesPath)
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
  let $pathToIndex := doc2html:get-path-to-index($stepsFromIndex)
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
  
  (: replace the function names description with images+name of the functions :) 
  let $xquSpec := "http://www.w3.org/TR/xquery-update-10/",
      $xqsSpec := "http://www.w3.org/TR/xquery-sx-10/#dt-sequential-function",
      $xq11Spec := "http://www.w3.org/TR/xquery-11/#FunctionDeclns"
  let $pathToIndex := doc2html:get-path-to-index($stepsFromIndex)
  let $imagesPath := concat($pathToIndex, "images/")
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

declare sequential function doc2html:createModuleTable($leftMenu as element(menu), $root, $moduleUri) { 
  for $cat1 in $leftMenu/category
  return block {
    doc2html:createModuleHelper($root, $cat1, $moduleUri);
    for $cat2 in $cat1/category
    let $table2 := $root/li[fn:last()]/ul
    return block {
      doc2html:createModuleHelper($table2, $cat2, $moduleUri);
      for $cat3 in $cat2/category
      let $table3 := $root/li[fn:last()]/ul/li[fn:last()]/ul
      return block {
        doc2html:createModuleHelper($table3, $cat3, $moduleUri);
      };
    };
  };
  
  $root;
};

declare function doc2html:createLeftMenu($leftMenu as element(menu), $isFunctionIndex as xs:boolean, $functionIndexPageName as xs:string) {
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
      
      for $link in $doc2html:externalLinks//a
      return
        <li>{$link}</li>
    )
    }
   </ul>
};

declare sequential function doc2html:createModuleHelper($table, $category, $moduleUri)
{
  block {
    insert nodes <li>{data($category/@name)}
    <ul>
    {
     for $module in $doc2html:indexCollector/module
      order by fn:data($module/@uri)
      return
        if(fn:starts-with(fn:string($module/@uri),data($category/@uri))
           and fn:not(fn:contains (fn:substring-after(data($module/@uri),fn:concat(data($category/@uri),'/')),'/'))) then
          if(fn:string($module/@uri) = $moduleUri) then
            <li><span class="leftmenu_active">{fn:substring-after(data($module/@uri),fn:concat(data($category/@uri),'/'))}</span></li>
          else 
            <li><a href="{$module/@file}">{fn:substring-after(data($module/@uri),fn:concat(data($category/@uri),'/'))}</a></li>
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
 : @return The content of the new index.html.
 :)
declare sequential function doc2html:generateIndexHtml($indexPath as xs:string, $menu, $modules) as document-node() {
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

declare sequential function doc2html:main(
  $modulePath as xs:string, $xqdocBuildPath as xs:string,
  $indexHtmlPath as xs:string
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
  </menu>
  let $menu :=
  <ul class="treeview" id="documentation">
    <span class="link">
      {string($leftMenu/@title)}
    </span>
  </ul>
  return doc2html:main($menu, $leftMenu, $modulePath, $xqdocBuildPath, $indexHtmlPath)
};

declare sequential function doc2html:main(
  $menu as element(ul),  $leftMenu as element(menu),
  $modulePath as xs:string, $xqdocBuildPath as xs:string,
  $indexHtmlPath as xs:string
) {
  declare $xqdocXmlPath   as xs:string := fn:concat($xqdocBuildPath, file:path-separator(), "xml");
  declare $xqdocXhtmlPath as xs:string := fn:concat($xqdocBuildPath, file:path-separator(), "xhtml");
  declare $xqdocSchemasPath as xs:string := fn:concat($xqdocBuildPath, file:path-separator(), "schemas");
  declare $functionIndexPageName as xs:string := "function_index.html";
  
  (: generate the XQDoc XML for all the modules :)
  if (file:mkdirs($xqdocXmlPath, false())) then
  (
    doc2html:clearFolder($xqdocXmlPath,"\.xml$"),
    doc2html:generateXQDocXml($modulePath, $xqdocXmlPath)
  )
  else
    error()
  ;
  
    
  (: generate the XQDoc XHTML for all the modules :) 
  let $absoluteXhtmlDir := concat($xqdocBuildPath, "/xhtml")
  return
  if (file:mkdirs($absoluteXhtmlDir, false())) then
  (
    doc2html:clearFolder($xqdocXhtmlPath,"xqdoc\.html$"),
    doc2html:gatherModules($xqdocXmlPath),
    doc2html:gatherSchemas($xqdocSchemasPath),    
    doc2html:generateXQDocXhtml($indexHtmlPath, $xqdocXmlPath, $xqdocXhtmlPath, $leftMenu, $modulePath, $functionIndexPageName),
    (
      (: generate the left menu for the Function Index XHTML :)
      let $leftFunction := doc2html:createLeftMenu($leftMenu, fn:true(), $functionIndexPageName)
      let $indexFunctionLeft := doc2html:createModuleTable($leftMenu, $leftFunction, $functionIndexPageName)
      return 
        doc2html:generateFunctionIndexXhtml($indexFunctionLeft,$xqdocXhtmlPath,$functionIndexPageName)
    )
  )
  else
    error()
  ;  
  
  let $left := doc2html:createLeftMenu($leftMenu, fn:false(), $functionIndexPageName)
  let $indexLeft := doc2html:createModuleTable($leftMenu, $left, "index.html")
  let $right := <ul />
  let $indexRight := doc2html:createModuleTable($leftMenu, $right, "index.html")
  let $doc := doc2html:generateIndexHtml($indexHtmlPath, $indexLeft, $indexRight)
  return doc2html:configure-xhtml($doc/*:html, 0, $modulePath)
  ;
 
};
