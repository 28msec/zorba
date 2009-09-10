(: Simple rest-get example :)

import module namespace zorba-rest = "http://www.zorba-xquery.com/zorba/rest-functions"; 
let $result := zorba-rest:get("http://tidy.sourceforge.net/docs/quickref.html")

let $payload := $result//zorba-rest:payload
return  $payload 
