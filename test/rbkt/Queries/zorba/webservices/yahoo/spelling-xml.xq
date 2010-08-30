import module namespace yahoo = 'http://www.zorba-xquery.com/modules/webservices/yahoo/search';
import module namespace shared="http://www.zorba-xquery.com/modules/webservices/yahoo/shared";

let $word := "madnna"
let $response := yahoo:spelling-xml($word)
return
  if(empty($response))
  then <test name="spelling-xml" succeed="false" message="Spelling suggestion not found." />
  else <test name="spelling-xml" succeed="true" message="Spelling suggestion found." />
