import module namespace yahoo = 'http://www.zorba-xquery.com/modules/webservices/yahoo/traffic';
import module namespace shared="http://www.zorba-xquery.com/modules/webservices/yahoo/shared";

let $location := "701 First Avenue, Sunnyvale, CA"
let $response := yahoo:traffic-report($location)
return
  if(empty($response))
  then <test name="traffic-report" succeed="false" message="Location not found." />
  else <test name="traffic-report" succeed="true" message="Location found." />
