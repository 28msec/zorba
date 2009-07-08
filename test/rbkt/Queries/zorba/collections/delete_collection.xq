import module namespace coll="http://www.zorba-xquery.com/zorba/collection-functions";

declare sequential function local:create() {
  coll:create-collection("test");
  coll:create-collection("test1", for $i in 1 to 10 return <a> { $i } </a> );
  exit returning coll:collection-exists("test") and coll:collection-exists("test1");
};

declare sequential function local:delete() {
  coll:delete-collection("test");
  coll:delete-collection("test1");
  exit returning fn:not(coll:collection-exists("test") and coll:collection-exists("test1"));
};

declare sequential function local:delete-all() {
  coll:delete-all-collections();
  exit returning fn:not(coll:collection-exists("test") and coll:collection-exists("test1"));
};

if (fn:not(local:create() and local:delete())) then
  fn:false()
else
  local:create() and local:delete-all()
