import module namespace d="www.data.com" at "match_veq_06.xqlib";

import module namespace doc = 
  "http://zorba.io/modules/store/documents";

import module namespace ddl = 
  "http://zorba.io/modules/store/static/collections/ddl";

import module namespace dml = 
  "http://zorba.io/modules/store/static/collections/dml";

import module namespace iddl = 
  "http://zorba.io/modules/store/static/indexes/ddl";


ddl:create($d:parents);

iddl:create($d:idx);

d:add-document(xs:anyURI("http://www.xmlteam.com/zorba/repo/index"), true());


dml:collection($d:parents)
,
"
"
