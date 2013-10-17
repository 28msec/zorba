import module namespace db28 = 
  "http://28.io/collections" at "match_veq_10.xqlib";

import module namespace dml = 
  "http://zorba.io/modules/store/static/collections/dml";

import module namespace ddl = 
  "http://zorba.io/modules/store/static/collections/ddl";

import module namespace iddl = 
  "http://zorba.io/modules/store/static/indexes/ddl";


ddl:create(xs:QName("db28:faqs"));

ddl:create(xs:QName("db28:answers"));

iddl:create(xs:QName("db28:question-id-idx"));


for $answers in dml:collection(xs:QName("db28:answers"))
let $id := $answers("question_id")
group by $id
let $count := count($answers)
order by $count descending
return {
 "title": dml:collection(xs:QName("db28:faqs"))[xs:string($id) eq xs:string(.("question_id"))]("title"),
 "answer_count": $count
}
