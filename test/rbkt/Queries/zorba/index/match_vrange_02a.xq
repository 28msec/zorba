
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
local:latest-docs(
    $uri as xs:string,
    $upper-bound as xs:string,
    $limit as xs:integer) as element(sports-content)*
{
  let $lower-bound := $uri
  let $results := subsequence(
    unordered 
    {
      dml:collection($d:documents)
      [substring-after(./doc/@base-uri, "www.foo.com/") ge $lower-bound and
       substring-after(./doc/@base-uri, "www.foo.com/") le $upper-bound]
    },
    1,
    $limit)/doc/sports-content

  for $group at $i in $results

  group by $title := $group/sports-metadata/@revision-id/string()

  let $max := max($group/sports-metadata/@date-time/string())

  return $group[sports-metadata/@date-time = $max][1]
};



declare variable $doc11 := 
document 
{
<doc base-uri="www.foo.com/folder1">
  <sports-content>
    <sports-metadata date-time="2012-12-31" revision-id="abc"/>
  </sports-content>
</doc>
};


declare variable $doc12 := 
document 
{
<doc base-uri="www.foo.com/folder1">
  <sports-content>
    <sports-metadata date-time="2013-01-01" revision-id="xyz"/>
  </sports-content>
</doc>
};


declare variable $doc21 := 
document 
{
<doc base-uri="www.foo.com/folder2">
  <sports-content>
    <sports-metadata date-time="2012-12-31" revision-id="xyz"/>
  </sports-content>
</doc>
};


declare variable $doc22 := 
document 
{
<doc base-uri="www.foo.com/folder2">
  <sports-content>
    <sports-metadata date-time="2011-12-31" revision-id="abc"/>
  </sports-content>
</doc>
};



ddl:create($d:documents);

dml:insert($d:documents, ($doc12, $doc11, $doc21, $doc22));

iddl:create($d:idx);


local:latest-docs("folder1", "folder3", 3),
"
"




