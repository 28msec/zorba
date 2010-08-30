import module namespace yahoo = 'http://www.zorba-xquery.com/modules/webservices/yahoo/geo';
import module namespace shared="http://www.zorba-xquery.com/modules/webservices/yahoo/shared";

let $location := "701 First Avenue, Sunnyvale, CA"
let $woeid := yahoo:woeid($location)
let $flags := "XRT"
let $response := yahoo:geocode-xml($woeid,$flags)
return
  if(empty($response))
  then <test name="geocode-xml" succeed="false" message="Location not found." />
  else <test name="geocode-xml" succeed="true" message="Location found." />
