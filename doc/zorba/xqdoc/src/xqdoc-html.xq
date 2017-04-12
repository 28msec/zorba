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

module namespace xqdoc-html = "http://www.zorba-xquery.com/xqdoc-html";

import module namespace file = "http://expath.org/ns/file";

import module namespace xqdoc = "http://zorba.io/modules/xqdoc";
import module namespace batch = "http://www.zorba-xquery.com/modules/xqdoc/batch" at "batch.xq";

declare namespace xqd = "http://www.xqdoc.org/1.0";
declare namespace z   = "http://zorba.io/manifest";
declare namespace xs  = "http://www.w3.org/2001/XMLSchema";

declare function xqdoc-html:id($label as xs:string)
as xs:string
{
 let $id := $label
 let $id := lower-case($id)
 let $id := replace($id, " ", "_")
 return $id
};

declare function xqdoc-html:sections($modules as object()*)
as element()*
{
  xqdoc-html:sections($modules, 1)
};

declare function xqdoc-html:sections($modules as object()*, $level as xs:integer)
as element()*
{
  for $group in $modules
  let $segments := tokenize($group[1]("project"), "/")
  let $int := string-join(subsequence($segments, 1, $level), "/")
  group by $int
  order by $int ascending
  return (
    for $module in $group
    let $segments := tokenize($module("project"), "/")
    where count($segments) = $level
    order by $module("ns") ascending
    return <module ns="{$module("ns")}" id="{$segments[last()]}" label="{$segments[last()]}" />
    ,
    let $has-section := exists(for $module in $group let $segments := tokenize($module("project"), "/") where count($segments) gt $level return $module)
    return if($has-section) then
      let $label := tokenize($group[1]("project"), "/")[$level]
      let $id := xqdoc-html:id($label)
      return
      <section label="{$label}" id="{$id}">
      {
        xqdoc-html:sections($group, $level + 1)
      }
      </section>
    else()
  )
};

declare function xqdoc-html:modules($manifest) as element()
{
<modules>
  <section id="modules" label="XQuery Modules">
  {
    let $sections := 
      for $module in $manifest/z:manifest/z:module
      let $uri := $module/z:uri/text()
      let $project := xqdoc:xqdoc($uri)/xqd:module/xqd:comment/xqd:custom[@tag="project"]/text()
      order by $project
      return
        if(exists($project))
        then { "ns": $uri, "project": $project }
        else { "ns": $uri, "project": $uri }
    return xqdoc-html:sections($sections)
  }
  </section>
</modules>
};
