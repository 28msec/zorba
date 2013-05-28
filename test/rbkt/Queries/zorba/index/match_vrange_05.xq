
import module namespace foo="www.accounts.com" at "match_vrange_05.xqlib";


import module namespace ddl = 
"http://www.zorba-xquery.com/modules/store/static/collections/ddl";

import module namespace dml = 
"http://www.zorba-xquery.com/modules/store/static/collections/dml";

import module namespace iddl = 
"http://www.zorba-xquery.com/modules/store/static/indexes/ddl";


ddl:create(xs:QName("foo:foo"));

iddl:create(xs:QName("foo:foo-index"));


count(for $i in dml:collection(xs:QName("foo:foo")) where $i("_id") gt "1" return $i)

