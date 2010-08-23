(:~
 : Yahoo! Maps Module
 : This module wraps many of the Yahoo! Maps APIs listed on <a href="http://developer.yahoo.com/maps/" target="_blank">http://developer.yahoo.com/maps/</a>.
 : @author Stephanie Russell
 : @version 1.0
 :)

module namespace yahoo = 'http://www.zorba-xquery.com/modules/web-services/yahoo/maps';
import module namespace http = "http://expath.org/ns/http-client";

(:~
 : Use shared module functions.
 :)
import module namespace shared="http://www.zorba-xquery.com/modules/web-services/yahoo/shared";

(:~
 : Use err module functions for throwing errors.
 :)
import module namespace err="http://www.zorba-xquery.com/modules/web-services/yahoo/errors-geo";

(:~
 : This function will return the xml response for a map query.
 : @see http://developer.yahoo.com/maps/rest/V1/index.html
 : @param $location string location for query
 : @return xml response of the map url for a given location
 :)
declare function yahoo:map-xml($location as xs:string)
{
  let $newLocation := fn:replace($location, " ", "+")
  return http:read(concat("http://local.yahooapis.com/MapsService/V1/mapImage?appid=",$shared:appid,"&amp;location=", $newLocation))
};

(:~
 : This function is for convenience. It will return the xml response of a map for a given location.
 : @see http://developer.yahoo.com/maps/rest/V1/index.html
 : @param $params parameter elements containing location (required as first element) and other optional parameters
 : @return xml response of the map for a given location
 :)
declare function yahoo:map-params-xml($params as element()+)
{
  let $parameters := yahoo:normalization($params,'=',"&amp;","")
  let $href := concat("http://local.yahooapis.com/MapsService/V1/mapImage?appid=",$shared:appid,"&amp;",$parameters)
  return http:read($href)
};

(:~
 : This function will return the url for a map of the location query.
 : @see http://developer.yahoo.com/maps/rest/V1/index.html
 : @param $location string location for query
 : @return the map url for a given location
 :)
declare function yahoo:map($location as xs:string) as xs:string?
{
  let $response := yahoo:map-xml($location)
  let $error := $response//*:Error
  let $error-message := $error/*:Message/data(.)
  return 
    if(empty($error))
    then $response[2]/data(.)
    else error($err:YS002, concat("Location not found: ", $error-message))
};
