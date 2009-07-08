import module namespace coll="http://www.zorba-xquery.com/zorba/collection-functions";

declare sequential function local:delete() {
  coll:delete-collection();
  exit returning fn:not(coll:collection-exists());
};

local:delete()
