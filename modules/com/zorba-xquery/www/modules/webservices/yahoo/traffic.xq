(:~
 : Yahoo! Traffic Module
 : This module wraps many of the Yahoo! Traffic APIs listed on <a href="http://developer.yahoo.com/traffic/" target="_blank">http://developer.yahoo.com/traffic/</a>.
 : @author Stephanie Russell
 : @version 1.0
 :)

module namespace yahoo = 'http://www.zorba-xquery.com/modules/webservices/yahoo/traffic';
import module namespace http = "http://expath.org/ns/http-client";

(:~
 : Use shared module functions.
 :)
import module namespace shared="http://www.zorba-xquery.com/modules/webservices/yahoo/shared";

(:~
 : Use err module functions for throwing errors.
 :)
import module namespace err="http://www.zorba-xquery.com/modules/webservices/yahoo/errors";

(:~
 : This function will return the xml response for a traffic report query.
 : @see http://developer.yahoo.com/traffic/rest/V1/index.html
 : @param $location string location for query
 : @return xml response of the traffic for a given location
 :)
declare function yahoo:traffic-report-xml($location as xs:string)
{
  let $href := concat("http://local.yahooapis.com/MapsService/V1/trafficData?appid=",$shared:appid,"&amp;location=",fn:encode-for-uri($location),"&amp;include_map=1")
  return http:read($href)
};

(:~
 : This function is for convenience. It will return the xml response for a given location.
 : @see http://developer.yahoo.com/traffic/rest/V1/index.html
 : @param $params parameter elements containing location (required as first element) and other optional parameters
 : @return xml response of the traffic for a given location
 :)
declare function yahoo:traffic-report-params-xml($params as element()+)
{
  let $parameters := shared:normalization($params,'=',"&amp;","")
  let $href := concat("http://local.yahooapis.com/MapsService/V1/trafficData?appid=",$shared:appid,"&amp;",$parameters)
  return http:read($href)
};

(:~
 : This function will return the traffic report for a given location
 : @see http://developer.yahoo.com/traffic/rest/V1/index.html
 : @param $location string location for query
 : @return traffic report
 :)
declare function yahoo:traffic-report($location as xs:string)
{
  let $response := yahoo:traffic-report-xml($location)
  let $error := $response//*:Error
  let $error-message := $error/*:Message/data(.)
  let $title := $response[2]//*:Title/data(.)
  let $result := $response//Result
  return 
    if(empty($error))
    then 
      if(empty($result))
      then "No traffic incidents to report at this location."
      else
        for $newLocation in $response[2]//*:Title/data(.)
        return ($newLocation,"&#xA;")
    else error($err:YS002, concat("Location not found: ", $error-message))
};
