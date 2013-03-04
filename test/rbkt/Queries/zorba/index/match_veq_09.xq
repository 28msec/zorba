

import module namespace db28 = 
"http://28.io/collections" at "match_veq_09.xqlib";

import module namespace dml = 
"http://www.zorba-xquery.com/modules/store/static/collections/dml";

import module namespace ddl = 
"http://www.zorba-xquery.com/modules/store/static/collections/ddl";

import module namespace iddl = 
"http://www.zorba-xquery.com/modules/store/static/indexes/ddl";


ddl:create(xs:QName("db28:faqs"));

ddl:create(xs:QName("db28:answers"));

iddl:create(xs:QName("db28:question-id-idx"));


for $answers in dml:collection(xs:QName("db28:answers"))
let $id := $answers("question_id")
group by $id
let $count := count($answers)
order by $count descending
return {
 "title": dml:collection(xs:QName("db28:faqs"))[$id eq .("question_id")]("title"),
 "answer_count": $count
}
