import module namespace coll="http://www.zorba-xquery.com/zorba/collection-functions";

declare sequential function local:create() 
{
  coll:create-collection("test");
  coll:insert-nodes-first("test", for $i in 1 to 10 return <a> { $i } </a>);
  exit returning (fn:count(fn:collection("test")) eq 10);
};

declare sequential function local:insert() 
{
  coll:insert-nodes-last("test", for $i in 11 to 13 return <b> { $i } </b>);
  exit returning fn:collection("test");
};


declare variable $x := 0;

set $x := local:create();

if (fn:not($x)) then
  fn:false()
else 
  local:insert();
