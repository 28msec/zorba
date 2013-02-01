import module namespace d="www.data.com" at "match_veq_06.xqlib";

import module namespace doc = 
"http://www.zorba-xquery.com/modules/store/dynamic/documents";

import module namespace ddl = 
"http://www.zorba-xquery.com/modules/store/static/collections/ddl";

import module namespace dml = 
"http://www.zorba-xquery.com/modules/store/static/collections/dml";

import module namespace iddl = 
"http://www.zorba-xquery.com/modules/store/static/indexes/ddl";


ddl:create($d:parents);

iddl:create($d:idx);

d:add-document(xs:anyURI("http://www.xmlteam.com/zorba/repo/index"), true());


dml:collection($d:parents)
,
"
"
