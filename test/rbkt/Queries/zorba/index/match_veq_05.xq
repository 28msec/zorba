import module namespace s="www.sessions.com" at "match_veq_05.xqlib";

import module namespace ddl = 
"http://www.zorba-xquery.com/modules/store/static/collections/ddl";

import module namespace dml = 
"http://www.zorba-xquery.com/modules/store/static/collections/dml";

import module namespace iddl = 
"http://www.zorba-xquery.com/modules/store/static/indexes/ddl";

import module namespace idml = 
"http://www.zorba-xquery.com/modules/store/static/indexes/dml";

declare construction strip;


declare variable $external_id external := "50";

declare variable $doc := 
<sessions>
<session id="50" duration="130"><data>1111111111</data></session>
<session id="12" duration="30"><data>2222222222</data></session>
<session id="50" duration="150"><data>3333333333</data></session>
</sessions>;


declare variable $doc2 := 
<sessions>
<session id="50" duration="130"><data>6666666</data></session>
<session id="70" duration="150"><data>7777777</data></session>
</sessions>;


ddl:create($s:sessions);

iddl:create(xs:QName("s:session-index"));

for $s in $doc/session
return dml:insert($s:sessions, $s);

for $s in $doc2/session
return dml:insert-first($s:sessions, $s);

for $s in $doc2/session
return dml:insert-last($s:sessions, $s);


let $id := $external_id

let $session := 
  for $session in dml:collection($s:sessions)[120 < @duration and @duration < 150]
  where $id eq $session/@id
  return $session

return
if (empty($session)) then 
{
  fn:trace($id, "no session with the given uuid")
}
else
{
  $session/data
}
,
"
"
