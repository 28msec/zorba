import module namespace db28 = 
"http://28.io/collections" at "match_veq_08.xqlib";

import module namespace dml = 
"http://www.zorba-xquery.com/modules/store/static/collections/dml";

import module namespace ddl = 
"http://www.zorba-xquery.com/modules/store/static/collections/ddl";

import module namespace iddl = 
"http://www.zorba-xquery.com/modules/store/static/indexes/ddl";


ddl:create(xs:QName("db28:faqs"));

iddl:create(xs:QName("db28:question-id-idx"));


for $obj in dml:collection(xs:QName("db28:faqs"))
where $obj("question_id") eq "4419499"
return $obj
