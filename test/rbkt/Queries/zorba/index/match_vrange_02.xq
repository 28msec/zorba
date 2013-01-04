
import module namespace d = "www.data.com" at "match_vrange_02.xqlib";

import module namespace ddl = 
"http://www.zorba-xquery.com/modules/store/static/collections/ddl";

import module namespace dml = 
"http://www.zorba-xquery.com/modules/store/static/collections/dml";

import module namespace iddl = 
"http://www.zorba-xquery.com/modules/store/static/indexes/ddl";

import module namespace idml = 
"http://www.zorba-xquery.com/modules/store/static/indexes/dml";

declare namespace an = "http://www.zorba-xquery.com/annotations";


declare function
local:collection($uri as xs:string) as document-node()*
{
  unordered 
  {
    for $d in dml:collection(xs:QName('d:documents'))
    where substring-after($d/doc/@base-uri, "www.foo.com/") gt $uri
    return $d
  }
};


declare function 
local:doc-exists($uri as xs:string) as xs:boolean
{
  count(
  dml:collection($d:documents)[substring-after(./doc/@base-uri, "www.foo.com/") eq $uri]
  ) = 1
};


declare function 
local:docs-since($date as xs:string) as document-node()*
{
  dml:collection($d:documents)[$date lt string(.//sports-content/sports-metadata/@date-time)]
};


declare variable $doc11 := 
document 
{
<doc base-uri="www.foo.com/folder1">
  <sports-content>
    <sports-metadata date-time="2012-12-31"/>
  </sports-content>
</doc>
};

declare variable $doc21 := 
document 
{
<doc base-uri="www.foo.com/folder2">
  <sports-content>
    <sports-metadata date-time="2012-12-31"/>
  </sports-content>
</doc>
};

declare variable $doc12 := 
document 
{
<doc base-uri="www.foo.com/folder1">
  <sports-content>
    <sports-metadata date-time="2013-01-01"/>
  </sports-content>
</doc>
};


ddl:create($d:documents);

dml:insert($d:documents, ($doc11, $doc21, $doc12));

iddl:create($d:idx);

local:collection("folder1"),
"
",
local:doc-exists("folder2"),
"
",
local:docs-since("2012-12-31"),
"
"




