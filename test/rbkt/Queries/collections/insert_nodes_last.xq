import module namespace coll="http://www.zorba-xquery.com/zorba/collection-functions";

declare sequential function local:create() {
  coll:create-collection("test");
  coll:insert-nodes-first("test", for $i in 1 to 10 return <a> { $i } </a>);
  exit with (fn:count(fn:collection("test")) eq 10);
};

declare sequential function local:insert() {
  coll:insert-nodes-last("test", for $i in 11 to 13 return <b> { $i } </b>);
  exit with fn:collection("test");
};

if (fn:not(local:create())) then
  fn:false()
else 
  local:insert()
