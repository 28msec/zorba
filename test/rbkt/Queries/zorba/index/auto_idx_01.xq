
import module namespace ddl = 
"http://www.zorba-xquery.com/modules/store/static/collections/ddl";

import module namespace dml = 
"http://www.zorba-xquery.com/modules/store/static/collections/dml";

import module namespace iddl = 
"http://www.zorba-xquery.com/modules/store/static/indexes/ddl";

import module namespace idml = 
"http://www.zorba-xquery.com/modules/store/static/indexes/dml";

import module namespace upd="www.upd_01.com" at "auto_idx_01.xqlib";


ddl:create(xs:QName("upd:auctions"));

iddl:create(xs:QName("upd:PersonId"));

