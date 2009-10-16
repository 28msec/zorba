import module namespace coll="http://www.zorba-xquery.com/zorba/collection-functions";

declare sequential function local:create() 
{
  coll:create-collection("test");
  coll:create-collection("test1");
  exit returning coll:collection-exists("test") and coll:collection-exists("test1");
};

declare sequential function local:create-and-insert() 
{
  coll:create-collection("test3", for $i in 1 to 10 return <a> { $i } </a>);
  exit returning coll:collection-exists("test3") and fn:count(fn:collection("test3")) eq 10;
};

declare variable $x := 0;
declare variable $y := 0;

set $x := local:create();
set $y := local:create-and-insert();
$x and $y;

