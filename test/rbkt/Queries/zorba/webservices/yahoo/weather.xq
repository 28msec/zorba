import module namespace yahoo = 'http://www.zorba-xquery.com/modules/webservices/yahoo/weather';
import module namespace shared="http://www.zorba-xquery.com/modules/webservices/yahoo/shared";

let $location := "701 First Avenue, Sunnyvale, CA"
let $response := yahoo:weather($location)
return
  if(empty($response))
  then <test name="weather" succeed="false" message="Location not found." />
  else <test name="weather" succeed="true" message="Location found." />
