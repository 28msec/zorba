import module namespace coll="http://www.zorba-xquery.com/zorba/collection-functions";

declare sequential function local:create() {
  coll:create-collection("test");
  exit returning coll:collection-exists("test");
};

declare sequential function local:insert() {
  coll:insert-nodes-first("test", for $i in 1 to 10 return <a> { $i } </a>);
  exit returning fn:collection("test");
};

if (fn:not(local:create())) then
  fn:false()
else 
  local:insert()
