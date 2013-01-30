
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


declare variable $doc11 := 
document 
{
<doc base-uri="www.foo.com/folder1">
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

declare variable $doc21 := 
document 
{
<doc base-uri="www.foo.com/folder2">
  <sports-content>
    <sports-metadata date-time="2012-12-31"/>
  </sports-content>
</doc>
};

declare variable $doc31 := 
document 
{
<doc base-uri="www.foo.com/folder3">
  <sports-content>
    <sports-metadata date-time="2012-12-31"/>
  </sports-content>
</doc>
};


ddl:create($d:documents);

dml:insert($d:documents, ($doc11, $doc31, $doc21, $doc12));

iddl:create($d:idx);


for $d in dml:collection(xs:QName('d:documents'))
let $key := substring-after($d/doc/@base-uri, "www.foo.com/")
where $key gt "folder1"
order by $key
return $d
,
"
",
for $d in dml:collection(xs:QName('d:documents'))
let $key1 := substring-after($d/doc/@base-uri, "www.foo.com/")
let $key2 := string($d//sports-content/sports-metadata/@date-time)
where $key1 ge "folder1" and $key1 lt "folder3" and $key2 gt "2012-12-30"
order by $key1, $key2
return $d
,
"
",
for $d in dml:collection(xs:QName('d:documents'))
let $key1 := substring-after($d/doc/@base-uri, "www.foo.com/")
let $key2 := string($d//sports-content/sports-metadata/@date-time)
where $key1 ge "folder1" and $key2 gt "2012-12-30" and $key1 lt "folder3"
order by $key1, $key2
return $d
,
"
",
for $d in dml:collection(xs:QName('d:documents'))
let $key1 := substring-after($d/doc/@base-uri, "www.foo.com/")
let $key2 := string($d//sports-content/sports-metadata/@date-time)
where $key1 ge "folder1" and $key2 gt "2012-12-30" and $key1 lt "folder3"
order by $key2
return $d
,
"
"







