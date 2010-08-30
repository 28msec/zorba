import module namespace google = 'http://www.zorba-xquery.com/modules/webservices/google/maps';

let $from := "701 First Avenue, Sunnyvale, CA"
let $to := "400 Oracle Parkway, Redwood City, CA"
let $avoid := ""
let $response := google:directions($from,$to,$avoid)
return
  if(empty($response))
  then <test name="test-directions" succeed="false" message="Directions are incorrect." />
  else <test name="test-directions" succeed="true" message="Directions are correct." />