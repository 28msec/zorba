import module namespace s="www.sessions.com" at "match_veq_02.xqlib";

import module namespace ddl = 
  "http://zorba.io/modules/store/static/collections/ddl";

import module namespace dml = 
  "http://zorba.io/modules/store/static/collections/dml";

import module namespace iddl = 
  "http://zorba.io/modules/store/static/indexes/ddl";


declare variable $external_id external := "50";

declare variable $doc := 
<sessions>
<session id="50"><data>1111111111</data></session>
<session id="12"><data>2222222222</data></session>
<session id="50"><data>3333333333</data></session>
</sessions>;


ddl:create($s:sessions);

iddl:create(xs:QName("s:session-index"));

for $s in $doc/session
return dml:insert($s:sessions, $s);


let $id := $external_id

let $session := 
  for $session in dml:collection($s:sessions)
  where xs:string($session/@id) eq $id
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
