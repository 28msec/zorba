import module namespace yahoo = 'http://www.zorba-xquery.com/modules/webservices/yahoo/geo';
import module namespace shared="http://www.zorba-xquery.com/modules/webservices/yahoo/shared";

let $location := "701 First Avenue, Sunnyvale, CA"
let $response := yahoo:woeid($location)
return
  if(empty($response))
  then <test name="woeid" succeed="false" message="Location not found." />
  else <test name="woeid" succeed="true" message="Location found." />
