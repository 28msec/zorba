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
import module namespace file = "http://expath.org/ns/file";

import module namespace xqdoc       = "http://zorba.io/modules/xqdoc";
import module namespace batch       = "http://www.zorba-xquery.com/modules/xqdoc/batch" at "batch.xq";
import module namespace fetch = "http://zorba.io/modules/fetch";
import module namespace xqdoc-html  = "http://www.zorba-xquery.com/xqdoc-html" at "xqdoc-html.xq";

declare namespace xqd = "http://www.xqdoc.org/1.0";
declare namespace z   = "http://zorba.io/manifest";
declare namespace xs  = "http://www.w3.org/2001/XMLSchema";

declare variable $zorbaManifestPath   as xs:string external;
declare variable $xhtmlRequisitesPath as xs:string external;
declare variable $xqdocBuildPath      as xs:string external;
declare variable $zorbaVersion        as xs:string external;

declare variable $slash := file:directory-separator();
declare variable $serXML:= <output:serialization-parameters xmlns:output="http://www.w3.org/2010/xslt-xquery-serialization">
                             <output:method   value="xml" />
                             <output:encoding value="UTF-8"/>
                           </output:serialization-parameters>;

declare %private function local:write-Doxygen(
  $content,
  $name as xs:string,
  $uri as xs:string?,
  $type as xs:string){
fn:serialize(<doxygen><compounddef id="{$name}-{$type}" kind="{$type}">
               <detaileddescription><para><h3>{concat("Content of ", $name, " " , $type)}</h3><programlisting type="{$type}">{fn:serialize($content,$serXML)}</programlisting></para></detaileddescription>
             </compounddef></doxygen>,$serXML)
};

(: Delete previous version of the documentation :)
if(file:exists($xqdocBuildPath))
then file:delete($xqdocBuildPath);
else ();

(: Copy Schemas :)
file:create-directory($xqdocBuildPath || $slash ||  "schemas");
file:create-directory($xqdocBuildPath || $slash || "xml");
let $base := $xhtmlRequisitesPath || $slash || ".." || $slash || ".." || $slash || ".." || $slash
let $dest := $xqdocBuildPath || $slash || "xml"
for $schema in file:list($base, true(), "*.xsd")
where not(ends-with($schema, ".ent.xsd"))
  and not(ends-with($schema, ".dtd.xsd"))
  and not(contains($schema, "URI_PATH"))
  and not(contains($schema, "QueryResults"))
let $schema-doc := doc($base || $slash || trace($schema, "schema"))
let $target-uri := $schema-doc/xs:schema/@targetNamespace/string()
let $name := replace(replace($target-uri, "http://", ""), "/", "_")
return {
  file:write-text($dest || $slash || replace(replace($target-uri, "http://", ""), "/", "_") || "-schema.xml",
                  local:write-Doxygen($schema-doc, $name, $target-uri, "schema"))
};

file:create-directory($xqdocBuildPath || $slash ||  "examples");
variable $manifest := parse-xml(file:read-text($zorbaManifestPath));
for $module in $manifest/z:manifest/z:module
let $uri := $module/z:uri/text()
let $xqdoc := xqdoc:xqdoc($uri)
let $module-name := tokenize($uri,"/")[last()]
return {
  (: Copy Examples :)
  for $example in $xqdoc//xqd:custom[@tag="example"]/text()
  let $source := $module/z:projectRoot/text() || $slash || $example
  let $test-name := trace(tokenize($source,"/")[last()], "example-name")
  let $destination := $xqdocBuildPath || $slash ||  "examples" || $slash || concat($module-name, "_", $test-name)
  let $dest := $xqdocBuildPath || $slash ||  "xml" || $slash || concat($module-name, "_", substring-before($test-name,".xq")) || "-example.xml"
  return {
    file:copy($source, $destination);
    file:write-text($dest,
                   local:write-Doxygen(file:read-text($source),$test-name, $uri, "example"));
  }
}

(: XQDoc Batch :)
let $static-folders := ("js", "css", "images")
let $static-folders := for $static in $static-folders return $xhtmlRequisitesPath || $slash || $static
let $template := parse-xml(file:read-text($xhtmlRequisitesPath || $slash || "template.xml"))/*
let $output-folder := $xqdocBuildPath
let $modules := xqdoc-html:modules($manifest)
return batch:build-xqdoc($output-folder, $static-folders, $template, $modules);

(: Copy modules :)
for $module in $manifest/z:manifest/z:module
let $uri := $module/z:uri/text()
let $module := fetch:content($uri, "MODULE")
return 
  file:write-text($xqdocBuildPath || $slash || "xml" || $slash || replace(substring-after($uri, "http://"),"/","_") || "-module.xml",
                  local:write-Doxygen($module, tokenize($uri,"/")[last()], $uri, "module"));

trace("","XQDoc generated successfully!");
