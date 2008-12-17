import module namespace coll="http://www.zorba-xquery.com/zorba/collection-functions";

declare sequential function local:delete() {
  coll:delete-collection(());
  exit with fn:not(coll:collection-exists(()));
};

local:delete()
