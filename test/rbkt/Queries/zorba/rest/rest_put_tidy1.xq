(: Simple rest-postTidy example :)

import module namespace zorba-rest = "http://www.zorba-xquery.com/zorba/rest-functions";

let $result := zorba-rest:postTidy('http://tidy.sourceforge.net/docs/quickref.html','"newline=CRLF","doctype=omit","force-output","bare=yes"', (), ()) 

let $payload := $result//zorba-rest:payload
return  $payload 
