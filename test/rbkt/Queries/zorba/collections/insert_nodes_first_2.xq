import module namespace coll="http://www.zorba-xquery.com/zorba/collection-functions";

declare sequential function local:insert() {
  coll:insert-nodes-first(for $i in 1 to 10 return <a> { $i } </a>);
  exit returning fn:collection();
};

local:insert()
