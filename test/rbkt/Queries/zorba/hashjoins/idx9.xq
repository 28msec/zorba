
import module namespace db = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";

import module namespace foo = "http://foo.com" at "idx9.xqlib";


db:create(xs:QName("foo:bet"));
db:create(xs:QName("foo:game"));

foo:bet()
