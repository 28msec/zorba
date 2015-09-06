xquery version "3.0";

(:
 : Copyright 2008-2011 The FLWOR Foundation.
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
 : Process XQDoc batches.
 : This module generates XQDoc HTML documentation from multiple
 : XQuery modules.
 :
 : @author William Candillon <a href="#">wcandillon at gmail dot com</a>
 : @project Zorba/XQDoc/Batch
 :)
module namespace batch = "http://www.zorba-xquery.com/modules/xqdoc/batch";

import module namespace functx = "http://www.functx.com";

import module namespace file = "http://expath.org/ns/file";

import module namespace xqdoc = "http://zorba.io/modules/xqdoc";
import module namespace menu  = "http://www.zorba-xquery.com/modules/xqdoc/menu" at "menu.xq";
import module namespace html  = "http://www.zorba-xquery.com/modules/xqdoc/html" at "html.xq";

declare namespace an   = "http://zorba.io/annotations";
declare namespace out  = "http://www.w3.org/2010/xslt-xquery-serialization";
declare namespace xq   = "http://www.xqdoc.org/1.0";
declare namespace h    = "http://www.w3.org/1999/xhtml";
declare namespace err  = "http://www.w3.org/2005/xqt-errors"; 

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "2.0";

(:~
 : Run an XQDoc batch.
 :
 : @param $output-folder Where to write the generated files.
 : @param $static-folders Where to copy the static files from. 
 : @param $template HTML layout of the generated files. The layount can contains different variables.
 : For instance: <pre class="ace-static" ace-mode="xml"><body><var name="page" /></body></pre> is a valid example.
 : Three variable names are available: <code>page</code>, <code>title</code>, and <code>menu</code>.
 : @param $modules Document describing the documentation project. For instance:
 : <pre class="ace-static" ace-mode="xml">
 : <modules>
 :  <namespace prefix="ann" uri="http://zorba.io/annotations" />
 :  <section id="modules" label="My Modules">
 :  <!-- Location hints are optionnals -->
 :    <module ns="http://example.com/mymodule" label="My Module" id="module" file="module.xq" />
 :  </section>
 : </modules>
 : </pre>
 :
 :)
declare %an:sequential function batch:build-xqdoc($output-folder as xs:string, $static-folders as xs:string*, $template as element(), $modules as element(modules))
{
  variable $output-xml-folder := concat($output-folder, file:directory-separator(), "xml", file:directory-separator());
  batch:create-xml-folder($output-xml-folder);
  batch:copy-static-folders($output-folder, $static-folders);
  for $page in $modules//*[local-name(.) = "section" or local-name(.) = "module"]
  let $menu := menu:menu($page, "")
  let $page-name := menu:item-uri($page)
  return {
    variable $p := batch:page($template, $menu, $page);
    trace($page-name, "Create Page");
    batch:create-page($output-folder, $page-name, $p);
    if(exists($page/@ns)) then {
      variable $doc-name := $page/@ns/string(.);
      $doc-name := substring-after($doc-name, "http://");
      $doc-name := replace($doc-name, "/", "_");
      $doc-name := concat($doc-name, ".xml");
      variable $output-xml := concat($output-xml-folder, $doc-name);
      trace($doc-name, "Save XML");
      batch:save-xml($output-xml, $page) 
    } else { () }
  }
};

declare %an:sequential function batch:create-xml-folder($folder as xs:string)
{
  if(not(file:is-directory($folder))) then
    file:create-directory($folder);
  else (); 
};

declare %an:sequential function batch:save-xml($output-file, $page)
{
  if($page instance of element(module)) then
    file:write-text($output-file, serialize(batch:xqdoc($page)));
  else
    ();
  (:
  variable $xqdoc := batch:xqdoc($page);
  :)
};

declare %an:nondeterministic function batch:page($template as element(), $menu as element(ul), $section as element())
as element(h:html)
{
  let $page :=
    typeswitch($section)
      case element(module)
      return html:convert(batch:xqdoc($section))

      case element(section)
      return batch:section($section)

      default return error(xs:QName('batch:UNKNOWN-ELEMENT'), "Element is neither an instance of section or module")
   let $title :=
     typeswitch($section)
       case element(module)
       return concat(functx:capitalize-first(batch:xqdoc($section)/xq:module/xq:name/text()), " Module")

       case element(section)
       return concat($section/@label, " Modules")

       default return ""
   return
     copy $tpl := $template
     modify (
       batch:process-variable($tpl, "page", $page),
       batch:process-variable($tpl, "title", $title),
       batch:process-variable($tpl, "menu", $menu)
     )
     return $tpl
};

declare %an:sequential function batch:create-page($output-folder as xs:string, $page-name as xs:string, $page as element(h:html))
{
  let $output-folder := batch:add-trailing-slash($output-folder)
  let $output := concat($output-folder, $page-name)
  return
    file:write-text(
      $output,
      serialize(
	$page,
        <out:serialization-parameters>
          <out:method value="xhtml" />
          <out:doctype-system value="about:legacy-compat" />
        </out:serialization-parameters>
      )
    )
};

declare %an:sequential function batch:copy-static-folders($output-folder as xs:string, $static-folders as xs:string*)
{
  for $folder in $static-folders
  let $folder-name   := file:base-name($folder)
  let $output-folder := batch:add-trailing-slash($output-folder)
  let $output        := concat($output-folder, $folder-name)
  return {
    if(file:is-directory($output)) then
      file:delete($output);
    else ();
    file:copy($folder, $output)
  }
};

declare function batch:section($sections as element(section)+)
as element(section)+
{
  batch:section($sections, 1)
};

declare function batch:section($sections as element(section)+, $level as xs:integer)
as element(section)+
{
  for $section in $sections
  return <section>
    {element {concat("h", $level)} { string($section/@label) }}
    <ul>
    {
      for $child in $section/*
      return <li>{
        if($child instance of element(module)) then
          <span><a href="{menu:item-uri($child)}">{string($child/@label)}</a>&#160;-&#160;{string($child/@ns)}</span>
        else
          batch:section($child, $level + 1)
      }</li>

    }
    </ul>
  </section>
};

declare %an:nondeterministic function batch:xqdoc($module as element(module))
as element(xq:xqdoc)
{
  try {
    let $xqdoc := if(exists($module/@file)) then
                    xqdoc:xqdoc-content(file:read-text($module/@file))
                  else
                    xqdoc:xqdoc($module/@ns) 
    let $namespaces := $module//ancestor::*[empty(..)]/namespace
    return batch:add-predeclared-namespaces($xqdoc, $namespaces)
  } catch err:XQST0046 {
    error(xs:QName('batch:MODULE-NOT-FOUND'), concat("Module ", $module/@ns, "  wasn't found. Maybe there is a typo in the namespace URI or the module isn't installed."))  
  }
};

declare function batch:add-predeclared-namespaces($xqdoc as element(xq:xqdoc), $namespaces as element(namespace)*)
as element(xq:xqdoc)
{
  copy $doc := $xqdoc
  modify (
    for $namespace in $namespaces
    let $prefix := string($namespace/@prefix)
    let $uri    := string($namespace/@uri)
    return
    (
      for $declared-namespace in $doc/xq:module/xq:custom[@tag="namespaces"]/xq:namespace[@uri = "" and @prefix = $prefix]
      return
        replace value of node $declared-namespace/@uri with $uri
      ,
      for $annotation in $doc//xq:annotation[@prefix = $prefix]
      return
        replace value of node $annotation/@namespace with $uri
    )
  )
  return $doc
};

declare function batch:add-trailing-slash($path as xs:string)
as xs:string
{
  if(ends-with($path, file:directory-separator())) then
    $path
  else
    concat($path, file:directory-separator())
};

declare %private updating function batch:process-variable($source as element(), $varname as xs:string, $value as item())
{
  let $vars := $source//h:var[@name=$varname]
  for $var in $vars
  return
    replace node $var with $value
};
