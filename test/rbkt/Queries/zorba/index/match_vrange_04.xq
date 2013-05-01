
import module namespace db28 = "http://28.io/collections" at "match_vrange_04.xqlib";

import module namespace ddl =
"http://www.zorba-xquery.com/modules/store/static/collections/ddl";

import module namespace dml =
"http://www.zorba-xquery.com/modules/store/static/collections/dml";

import module namespace iddl = 
"http://www.zorba-xquery.com/modules/store/static/indexes/ddl";


ddl:create(xs:QName("db28:foo"));

iddl:create(xs:QName("db28:foo__id_"));

for $i in dml:collection(xs:QName("db28:foo"))
where $i("_id") eq "3"
return $i
