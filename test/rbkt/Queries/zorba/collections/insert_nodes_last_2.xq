import module namespace coll="http://www.zorba-xquery.com/zorba/collection-functions";

declare sequential function local:insert() {
  coll:insert-nodes-last(for $i in 11 to 13 return <b> { $i } </b>);
  exit with fn:collection();
};
  
local:insert()
