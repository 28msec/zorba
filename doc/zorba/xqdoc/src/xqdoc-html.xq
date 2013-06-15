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

import module namespace xqdoc       = "http://www.zorba-xquery.com/modules/xqdoc";
import module namespace batch       = "http://www.zorba-xquery.com/modules/xqdoc/batch";
import module namespace xqdoc-html  = "http://www.zorba-xquery.com/xqdoc-html" at "xqdoc-html.xqy";

declare namespace xqd = "http://www.xqdoc.org/1.0";
declare namespace z   = "http://www.zorba-xquery.com/manifest";
declare namespace xs  = "http://www.w3.org/2001/XMLSchema";

declare variable $zorbaManifestPath   as xs:string external;
declare variable $xhtmlRequisitesPath as xs:string external;
declare variable $xqdocBuildPath      as xs:string external;
declare variable $zorbaVersion        as xs:string external;

declare variable $slash := file:directory-separator();

(: Delete previous version of the documentation 
file:delete($xqdocBuildPath || $slash ||  "schemas");:)

(: Copy Schemas :)
file:create-directory($xqdocBuildPath || $slash ||  "schemas");
let $base := $xhtmlRequisitesPath || $slash || ".." || $slash || ".." || $slash || ".." || $slash 
for $schema in file:list($base, true(), "*.xsd")
where not(ends-with($schema, ".ent.xsd")) and not(ends-with($schema, ".dtd.xsd"))
let $schema-doc := doc($base || $slash || trace($schema, "schema"))
let $target-uri := $schema-doc/xs:schema/@targetNamespace/string()
return {
  file:write($xqdocBuildPath || $slash || "schemas" || $slash || replace(replace($target-uri, "http://", ""), "/", "_") || ".xsd" , $schema-doc, ())
};

variable $manifest := parse-xml(file:read-text($zorbaManifestPath));
for $module in $manifest/z:manifest/z:module
let $uri := $module/z:uri/text()
let $xqdoc := xqdoc:xqdoc($uri)
return {
  (: Copy Examples :)
  for $example in $xqdoc//xqd:custom[@tag="example"]/text()
  let $source := $module/z:projectRoot/text() || file:directory-separator() || $example
  let $destination := $xqdocBuildPath || file:directory-separator() || $example
  let $base-dest := file:dir-name($destination)
  return {
    file:copy($source, $xqdocBuildPath || file:directory-separator() || $example); 
  }
}

(: XQDoc Batch :)
let $static-folders := ("js", "css", "images")
let $static-folders := for $static in $static-folders return $xhtmlRequisitesPath || file:directory-separator() || $static
let $template := parse-xml(file:read-text($xhtmlRequisitesPath || file:directory-separator() || "template.xml"))/*
let $output-folder := $xqdocBuildPath
let $modules := xqdoc-html:modules($manifest)
return batch:build-xqdoc($output-folder, $static-folders, $template, $modules);
trace("","XQDoc generated successfully!");