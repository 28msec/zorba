(:
 : Copyright 2006-2011 The FLWOR Foundation.
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

import module namespace http = "http://www.zorba-xquery.com/modules/http-client";
import module namespace file = "http://expath.org/ns/file";
import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";
import module namespace map = "http://www.zorba-xquery.com/modules/store/data-structures/unordered-map";
(:import module namespace lcc = "http://www.zorba-xquery.com/scripts/link-crawler-collections" at "link_crawler_collections.xq";:)
import module namespace tidy="http://www.zorba-xquery.com/modules/converters/html";
import schema namespace tidy-options="http://www.zorba-xquery.com/modules/converters/html-options";
import schema namespace httpsch = "http://expath.org/ns/http-client";
declare namespace ann = "http://www.zorba-xquery.com/annotations";
declare namespace xhtml="http://www.w3.org/1999/xhtml";
declare namespace output="http://www.w3.org/2010/xslt-xquery-serialization";
declare namespace err="http://www.w3.org/2005/xqt-errors";

declare variable $result-file as xs:string external; (:PROJECT_SOURCE_DIR:)

declare variable $top-uri  as xs:string := "http://www.zorba-xquery.com/site2/html/index.html"; (: the start page :)
declare variable $uri-host as xs:string := "http://www.zorba-xquery.com/site2/"; (:  what differentiates an internal uri :)

declare variable $supported-media-types as xs:string+ := ("text/xml", "application/xml", "text/xml-external-parsed-entity", "application/xml-external-parsed-entity",
                            "application/atom+xml", "text/html");
                            
declare variable $internal-uris as xs:QName := xs:QName("internal-uris");
declare variable $external-uris as xs:QName := xs:QName("external-uris");

declare variable $broken-internal as xs:QName := xs:QName("local:broken-internal");
declare variable $broken-external as xs:QName := xs:QName("local:broken-external");
declare variable $pages-cannot-parse as xs:QName := xs:QName("local:pages-cannot-parse");


declare function local:my-substring-before($s1 as xs:string, $s2 as xs:string) as xs:string
{
  let $sb := fn:substring-before($s1, $s2)
  return 
    if($sb = "") then
      $s1
    else
      $sb
};


declare %ann:sequential function local:get-uris-from-page($uri as xs:string, 
                                                          $reluri as xs:string,
                                                          $call-from as xs:string)
{
  variable $method;
  if(fn:starts-with($uri, $uri-host)) then
  {
    map:insert($internal-uris, $uri, $uri);
    $method := "GET";
  }
  else
  {
    map:insert($external-uris, $uri, $uri);
    $method := "HEAD";
  }
  fn:trace($uri, "");
  
  variable $load-result;
  variable $content-string;
  try{
    $load-result := http:send-request(<httpsch:request method="{$method}" href="{$uri}"/>, (), ());
    if($load-result[1]/@status eq 200) then
      if(fn:starts-with($uri, $uri-host)) then
      {
        $content-string := string($load-result[2]);
        let $media-type := local:my-substring-before($load-result[1]/httpsch:header[@name = 'Content-Type'][1]/fn:string(@value), ";")
        return
          if($media-type = "text/html") then
            let $content := tidy:parse($content-string,           
                                        <options xmlns="http://www.zorba-xquery.com/modules/converters/html-options" >
                                          <tidyParam name="output-xml" value="yes" />
                                          <tidyParam name="doctype" value="omit" />
                                          <tidyParam name="quote-nbsp" value="no" />
                                          <tidyParam name="char-encoding" value="utf8" />
                                          <tidyParam name="newline" value="LF" />
                                          <tidyParam name="tidy-mark" value="no" />
                                          <tidyParam name="new-inline-tags" value="nav header section article footer xqdoc:custom d c options json-param" />
                                        </options>)
            for $other-uri2 in  ($content//*:a/string(@href), 
                                $content//*:link/string(@href), 
                                $content//*:script/string(@src),
                                $content//*:img/string(@src),
                                $content//*:area/string(@href)
                               )
            let $other-uri := fn:normalize-space($other-uri2)
            let $absuri := local:my-substring-before(fn:resolve-uri($other-uri, $uri), "#")
            return 
              if(fn:not(fn:starts-with($other-uri, "#")) and
                 fn:empty(map:get($internal-uris, $absuri)) and
                 fn:empty(map:get($external-uris, $absuri))) then
                local:get-uris-from-page($absuri, $other-uri, $uri);
              else (:already followed this link:)
                ();
          else(: it's binary :)
            fn:trace((" has binary content ", $media-type), "");
       }
       else(:success loading external link:)
         ();
    else (: broken link :)
      if(fn:starts-with($uri, $uri-host)) then
      {
        dml:insert-nodes-last($broken-internal, <internal-broken-uri>
                                                    <uri>{$reluri}</uri>
                                                    <call-from>{$call-from}</call-from>
                                                    <media-type>{local:my-substring-before($load-result[1]/httpsch:header[@name = 'Content-Type'][1]/fn:string(@value), ";")}</media-type>
                                                    </internal-broken-uri>);
      }
      else
      {
        dml:insert-nodes-last($broken-external, <external-broken-uri>
                                                    <uri>{$uri}</uri>
                                                    <call-from>{$call-from}</call-from>
                                                    <media-type>{local:my-substring-before($load-result[1]/httpsch:header[@name = 'Content-Type'][1]/fn:string(@value), ";")}</media-type>
                                                    </external-broken-uri>);
      }
  }catch ZXQP0003
  {
    dml:insert-nodes-last($pages-cannot-parse, <page-cannot-parse>
                                                 <uri>{$uri}</uri>
                                                 <reluri>{$reluri}</reluri>
                                                 <call-from>{$call-from}</call-from>
                                                 <err-code>{$err:code}</err-code>
                                                 <err-description>{$err:description}</err-description>
                                                 <err-value>{$err:value}</err-value>
                                                 <err-module>{$err:module}</err-module>
                                                 <err-line>{$err:line-number}</err-line>
                                                 </page-cannot-parse>);
    try{ (: tidy failed to parse the html, use regex:)
        let $content := $content-string
        let $search := fn:analyze-string($content, "(&lt;|&amp;lt;|<)(((a|link|area).+?href)|((script|img).+?src))=([""'])(.*?)\7")
        for $other-uri2 in  $search//fn:group[@nr=8]/fn:string()
        let $other-uri := fn:normalize-space($other-uri2)
        let $absuri := local:my-substring-before(fn:resolve-uri($other-uri, $uri), "#")
        return 
          if(fn:not(fn:starts-with($other-uri, "#")) and
             fn:empty(map:get($internal-uris, $absuri)) and
             fn:empty(map:get($external-uris, $absuri))) then
            local:get-uris-from-page($absuri, $other-uri, $uri);
          else (:already followed this link:)
            ();          
    }catch *
    {
      dml:insert-nodes-last($pages-cannot-parse, <page-cannot-parse>
                                                   <uri>{$uri}</uri>
                                                   <reluri>{$reluri}</reluri>
                                                   <call-from>{$call-from}</call-from>
                                                   <err-code>{$err:code}</err-code>
                                                   <err-description>{$err:description}</err-description>
                                                   <err-value>{$err:value}</err-value>
                                                   <err-module>{$err:module}</err-module>
                                                   <err-line>{$err:line-number}</err-line>
                                                   </page-cannot-parse>);
    }          
  }catch *
  {
    dml:insert-nodes-last($pages-cannot-parse, <page-cannot-parse>
                                                 <uri>{$uri}</uri>
                                                 <reluri>{$reluri}</reluri>
                                                 <call-from>{$call-from}</call-from>
                                                 <err-code>{$err:code}</err-code>
                                                 <err-description>{$err:description}</err-description>
                                                 <err-value>{$err:value}</err-value>
                                                 <err-module>{$err:module}</err-module>
                                                 <err-line>{$err:line-number}</err-line>
                                                 </page-cannot-parse>);
  }          
}; 



map:create($internal-uris, xs:QName("xs:string"));
ddl:create($broken-internal);
map:create($external-uris, xs:QName("xs:string"));
ddl:create($broken-external);
ddl:create($pages-cannot-parse);

local:get-uris-from-page($top-uri, $top-uri, "");

(:display results:)
let $full-report :=
<link-crawler website="{$top-uri}">
<internal-broken-uris>
{for $i in dml:collection($broken-internal)
let $u := $i/uri
group by $u
return $i}
</internal-broken-uris>
<pages-cannot-parse>
{for $e in dml:collection($pages-cannot-parse)
let $u := $e/uri
group by $u
return $e}
</pages-cannot-parse>
<external-uris>
{for $e in map:keys($external-uris)
let $v := $e/attribute/@value
group by $v
return <external-uri>{$e}</external-uri>}
</external-uris>
<external-broken-uris>
{for $e in dml:collection($broken-external)
let $u := $e/uri
group by $u
return  $e}
</external-broken-uris>

</link-crawler>

return
file:write($result-file,
            $full-report,
            <output:serialization-parameters>
                <output:indent value="yes"/>
            </output:serialization-parameters>)

