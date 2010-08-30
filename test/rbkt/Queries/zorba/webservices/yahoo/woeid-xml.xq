import module namespace yahoo = 'http://www.zorba-xquery.com/modules/webservices/yahoo/geo';
import module namespace shared="http://www.zorba-xquery.com/modules/webservices/yahoo/shared";

let $location := "701 First Avenue, Sunnyvale, CA"
let $response := yahoo:woeid-xml($location)
return
  if(empty($response))
  then <test name="woeid-xml" succeed="false" message="Location not found." />
  else <test name="woeid-xml" succeed="true" message="Location found." />
