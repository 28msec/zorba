import module namespace ddl = "http://zorba.io/modules/store/dynamic/collections/ddl";

declare namespace err = "http://www.w3.org/2005/xqt-errors";

import module namespace xqsx = "http://www.zorba-xquery.com/zorba/scripting";

declare variable $coll1 := xs:QName("collection1");
declare variable $coll2 := xs:QName("collection2");

ddl:create($coll1);

(
try
{
  { ddl:create($coll1); () }
}
catch * 
{
  <exception>{$err:code} : {$err:description}</exception>
}
,
"
"
,
try
{
  { (ddl:create($coll2), ddl:create($coll2)); () }
}
catch * 
{
  <exception>{$err:code} : {$err:description}</exception>
}
,
"
"
,
ddl:is-available-collection($coll1)
,
"
"
,
ddl:available-collections()
,
"
",
xqsx:apply(ddl:delete($coll1))
,
"
"
,
ddl:is-available-collection($coll1)
,
"
"
)

