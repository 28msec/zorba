import module namespace ddl = 
  "http://zorba.io/modules/store/static/collections/ddl";

import module namespace dml = 
  "http://zorba.io/modules/store/static/collections/dml";

import module namespace iddl = 
  "http://zorba.io/modules/store/static/indexes/ddl";

import module namespace idml = 
  "http://zorba.io/modules/store/static/indexes/dml";

import module namespace upd="www.upd_01.com" at "auto_idx_01.xqlib";

ddl:create(xs:QName("upd:auctions"));

iddl:create(xs:QName("upd:PersonId"));
