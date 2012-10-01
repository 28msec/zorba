

import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";

import module namespace ns = 'http://www.28msec.com/templates/guestbook/guestbook' at "guestbook.xqlib";

declare variable $local:function as xs:string := "list";

variable $local:err-msg := concat('http://www.28msec.com/templates/guestbook/guestbook: ', 'handler does not contain function ', $local:function, '()');

variable $local:err-obj := fn:QName('http://www.28msec.com/templates/guestbook/guestbook', $local:function);

ddl:create($ns:entries);

variable $local:result :=
  switch ($local:function)
  case 'list' return ns:list()
  case 'add' return ns:add()
  default return fn:error(xs:QName("ns:foo"), $local:err-msg, $local:err-obj);

if (exists($local:result))
then
  if (fn:false())
  then
    $local:result
  else
    fn:serialize($local:result)
else ()
