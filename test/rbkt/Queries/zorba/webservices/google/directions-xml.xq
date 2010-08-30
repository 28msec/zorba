import module namespace google = 'http://www.zorba-xquery.com/modules/webservices/google/maps';

let $from := "701 First Avenue, Sunnyvale, CA"
let $to := "400 Oracle Parkway, Redwood City, CA"
let $avoid := ""
let $response := google:directions-xml($from,$to,$avoid)
return
  if(xs:string($response/@status/data(.)) eq "200")
  then <test name="test-directions-xml" succeed="true" message="Directions request is valid." />
  else <test name="test-directions-xml" succeed="false" message="Directions request is invalid." />