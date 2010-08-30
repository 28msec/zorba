import module namespace yahoo = 'http://www.zorba-xquery.com/modules/webservices/yahoo/geo';
import module namespace shared="http://www.zorba-xquery.com/modules/webservices/yahoo/shared";

let $location := "37.775391-122.412209"
let $flags := "XRT"
let $response := yahoo:location-xml($location,$flags)
return
  if(empty($response))
  then <test name="location-xml" succeed="false" message="Location not found." />
  else <test name="location-xml" succeed="true" message="Location found." />
