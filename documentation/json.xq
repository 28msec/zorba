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
 : Convert an XQDoc document into an HTML document.
 :
 : This module contains a single <code>convert()</code> function
 : that transform an XQDoc document into an HTML document.
 : Usage:
 : <pre class="ace-static" ace-mode="xquery">
 : let $xqdoc := xqdoc:xqdoc("http://expath.org/ns/file")
 : return html:convert($xqdoc)
 : </pre>
 :
 : @author William Candillon <a href="#">wcandillon at gmail dot com</a>
 :
 :)

module namespace html = "http://www.zorba-xquery.com/modules/xqdoc/json";

declare namespace xq = "http://www.xqdoc.org/1.0";
declare namespace o = "http://www.w3.org/2010/xslt-xquery-serialization";
(:
declare copy-namespaces no-preserve, inherit;
:)

declare function html:normalize-anchors($node) {
  copy $new := $node
  modify (
    for $href in $new//*/@href
    where starts-with(string($href), "#")
    return replace value of node $href with ("?anchor=" || substring($href, 2))
  )
  return $new
};

declare function html:convert($xqdoc as element(xq:xqdoc))
as object()
{
  let $module := html:normalize-anchors($xqdoc/xq:module)
  let $ns := normalize-space($module/xq:uri/text())
  let $comment := $module/xq:comment
  let $namespaces := $module/xq:custom[@tag = "namespaces"]/xq:namespace
  let $prefix := $xqdoc/xq:functions/xq:function[1]/xq:name/text()/substring-before(., ":")
  let $prefix := if(exists($prefix)) then $prefix else $xqdoc/xq:variables/xq:variable[1]/xq:uri/text()/substring-before(., ":")
  let $variables := for $variable in $xqdoc/xq:variables/xq:variable[not(.//xq:annotation/@localname = "private")] order by $variable/xq:name/text() ascending return $variable
  let $functions := for $function in $xqdoc/xq:functions/xq:function[not(html:is-function-private(.))] order by concat($function/xq:name/text(), $function/@arity) ascending return $function
  let $description := $comment/xq:description/node()
  return
  {
    "ns": $ns,
    "description": serialize($description, ()),
    "sees": [$comment/xq:see ! serialize(., ())],
    "authors": [$comment/xq:author ! serialize(., ())],
    "version": $comment/xq:custom[@tag =  "XQuery version"]/text(),
    "encoding": $comment/xq:custom[@tag = "encoding"]/text(),
    "namespaces": [$namespaces ! { "uri": ./@uri/string(), "prefix": ./@prefix/string() }],
    "functions": [
      for $function in $functions
      let $description := $function/xq:comment/xq:description/node()
      let $summary := if($description) then html:description-summary($function/xq:comment/xq:description) else ()
      let $qname  := $function/xq:name/text()
      let $name   := $qname/substring-after(., ":")
      let $arity  := string($function/@arity)
      let $params := $function/xq:parameters/xq:parameter
      let $return := $function/xq:return
      let $errors := $function/xq:comment/xq:error
      return {
        "arity": number($function/@arity),
        "name": $name,
        "qname": $qname,
        "signature": substring-after($function/xq:signature/text(), $function/xq:name/text()),
        "description": serialize($description, ()),
        "summary": serialize($summary, ()),
        "annotation_str": html:serialize-annotations($function/xq:annotations),
        "annotations": [
          for $a in $function/xq:annotations/xq:annotation
          return {
            "prefix": $a/@prefix/string(),
            "ns": $a/@namespace/string(),
            "name": $a/@localname/string(),
            "value": $a/@value/string()
          }
        ],
        "updating": html:is-function-updating($function),
        "parameters": [
          for $param in $params
          return {
            "name": $param/xq:name/string(),
            "type": $param/xq:type/string(),
            "occurence": $param/xq:type/@occurence/string(),
            "description":
                      let $variable := concat('$', $param/xq:name/text())
                      let $description := $function/xq:comment/xq:param[starts-with(./text()[1], $variable)][1]
                      let $description := if(exists($description)) then
                                            copy $d := $description
                                            modify (
                                              rename node $d as "div",
                                              let $text-node := $d/text()[starts-with(., $variable)]
                                              return
                                                replace value of node $text-node with replace($text-node, concat("\$", $param/xq:name/text()), "")
                                            )
                                            return $d
                                          else ()
                      return serialize($description, ())

          }
        ],
        "returns": {
          "type": $return/xq:type/text(),
          "description": serialize($function/xq:comment/xq:return/node(), ())
        },
        "errors": [for $error in $errors return serialize($error, ())]
      }
    ],
    "variables": [
          for $variable at $i in $variables
          let $name := $variable/xq:uri/text()
          let $type := $variable/xq:comment/xq:custom[@tag = "type"]/text()
          let $type := if(empty($type)) then "item()*" else $type
          return {
            "name": $name,
            "type": $type,
            "description": serialize($variable/xq:comment/xq:description/node(), ())
          }
    ]
  }
};

declare %private function html:normalize-pre($pre as element(pre))
as element(pre)
{
  <pre>
  {$pre/attribute()}
  {serialize($pre/node(), <o:serialization-parameters></o:serialization-parameters>)}
  </pre>
};

declare %private function html:normalize($nodes as node()*)
as item()*
{
  ()
(:
  copy $html := $nodes
  modify (
    for $node in $html//*[empty(./node()[not(. instance of attribute())]) and local-name(.) = $html:empty-tags-to-delete]
    return delete node $node,
    for $pre in $html//pre[exists(*)]
    return replace node $pre with html:normalize-pre($pre)
  )
  return $html
:)
};

declare %private function html:text($nodes as node()*)
as xs:string?
{
  string-join( 
    for $node in $nodes
    return
      if($node instance of text()) then
        $node
      else
        html:text($node/node())
  , " ")
};

declare %private function html:description-summary($description as element(xq:description))
as element(p)
{
  let $text := html:text($description)
  let $text := if(contains($text, ".")) then concat(substring-before($text, "."), ".") else $text
  return
     <p>{$text}</p>
};

declare %private function html:serialize-params($params as element(xq:parameters)?)
as xs:string*
{
  let $params :=
    for $param in $params/xq:parameter
    return
      concat("$", $param/xq:name/text(), " as ", $param/xq:type/text(), $param/xq:type/@occurrence)
  return
    if(exists($params)) then
      concat("
    ", string-join($params, ",
    "), "
")
    else ()
};

declare %private function html:serialize-annotations($annotations as element(xq:annotations)?)
as xs:string?
{
  let $result :=
    string-join(
      let $namespaces := $annotations/ancestor::*[empty(..)]//xq:module/xq:custom[@tag = "namespaces"]/xq:namespace
      for $annotation in $annotations/xq:annotation
      let $ns := $annotation/@namespace/string(.)
      let $prefix := $annotation/@prefix/string(.)
      return
        concat("%", if(exists($prefix)) then concat($prefix, ":") else (), $annotation/@localname)
    , " ")
  return
    if($result != "") then
      concat(" ", $result)
    else
      $result
};

declare %private function html:function-properties($function as element(xq:function))
as element(span)*
{
  if(html:is-function-external($function)) then
    <span class="external">&#160;</span>
  else(),
  if(html:is-function-sequential($function)) then
    <span class="sequential">&#160;</span>
  else(),
  if(html:is-function-updating($function)) then
    <span class="updating">&#160;</span>
  else (),
  if(html:is-function-variadic($function)) then
    <span class="variadic">&#160;</span>
  else (),
  if(html:is-function-streamable($function)) then
    <span class="streamable">&#160;</span>
  else (),
  if(html:is-function-nondeterministic($function)) then
    <span class="nondeterministic">&#160;</span>
  else ()
};

declare %private function html:is-function-updating($function as element(xq:function))
as xs:boolean
{
  $function/xq:signature/text()/contains(substring-before(., $function/xq:name/text()), " updating ")
};

declare %private function html:is-function-private($function as element(xq:function))
as xs:boolean
{
  exists($function/xq:annotations/xq:annotation[@localname = "private" and @namespace = "http://www.w3.org/2005/xpath-functions"])
};

declare %private function html:is-function-nondeterministic($function as element(xq:function))
as xs:boolean
{
  exists($function//xq:annotation[@namespace = "http://www.zorba-xquery.com/annotations" and @localname = "nondeterministic"]) 
};

declare %private function html:is-function-streamable($function as element(xq:function))
as xs:boolean
{
  exists($function//xq:annotation[@namespace = "http://www.zorba-xquery.com/annotations" and @localname = "streamable"]) 
};

declare %private function html:is-function-variadic($function as element(xq:function))
as xs:boolean
{
  exists($function//xq:annotation[@namespace = "http://www.zorba-xquery.com/annotations" and @localname = "variadic"]) 
};

declare %private function html:is-function-sequential($function as element(xq:function))
as xs:boolean
{
  exists($function//xq:annotation[@namespace = "http://www.zorba-xquery.com/annotations" and @localname = "sequential"]) 
};

declare %private function html:is-function-external($function as element(xq:function))
as xs:boolean
{
  $function/xq:signature/text()/ends-with(., " external")
};
