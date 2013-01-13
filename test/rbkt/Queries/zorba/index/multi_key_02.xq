import module namespace d = "www.data.com" at "multi_key_02.xqlib";

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
<doc key1="10" key2="5" key3="3"/>;

declare variable $doc12 := 
<doc key1="10" key2="6" key3="5"/>;

declare variable $doc21 := 
<doc key1="20" key2="5" key3="4"/>;

declare variable $doc22 := 
<doc key1="20" key2="5" key3="30"/>;


ddl:create($d:documents);

dml:insert($d:documents, ($doc11, $doc21, $doc12, $doc22));

iddl:create($d:idx);

idml:probe-index-range-value(
     $d:idx,
     10, (), true(),  false(), false(), false(),
     (), (), false(), false(), false(), false(),
     20, (), true(), false(), false(), false())
,
"
"

