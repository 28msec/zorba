import module namespace yahoo = 'http://www.zorba-xquery.com/modules/webservices/yahoo/search';
import module namespace shared="http://www.zorba-xquery.com/modules/webservices/yahoo/shared";

let $word := "madnna"
let $response := yahoo:spelling($word)
return
  if(empty($response))
  then <test name="spelling" succeed="false" message="Spelling suggestion not found." />
  else <test name="spelling" succeed="true" message="Spelling suggestion found." />
