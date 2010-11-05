(:~
 : Yahoo! GeoPlanet™ Module
 : This module wraps many of the Yahoo! GeoPlanet™ APIs listed on <a href="http://developer.yahoo.com/geo/geoplanet/" target="_blank">http://developer.yahoo.com/geo/geoplanet/</a>.
 : @author Stephanie Russell
 : @see <a href="http://developer.yahoo.com/geo/geoplanet/" target="_blank">http://developer.yahoo.com/geo/geoplanet/</a>
 :
 :)

module namespace yahoo = 'http://www.zorba-xquery.com/modules/webservices/yahoo/geo';
import module namespace http = "http://www.zorba-xquery.com/modules/http-client";

(:~
 : Use shared module functions.
 :)
import module namespace shared="http://www.zorba-xquery.com/modules/webservices/yahoo/shared";

(:~
 : Use err module functions for throwing errors.
 :)
import module namespace err="http://www.zorba-xquery.com/modules/webservices/yahoo/errors";

(:~
 : This function will return the xml response of the query for a $location.
 : @see http://developer.yahoo.com/geo/geoplanet/guide/api_docs.html#api_overview
 : @param $location string location for query
 : @return xml response including longitude, latitude, and woeid.
 :)
declare function yahoo:woeid-xml($location as xs:string)
{
  let $x := fn:replace($location, " ", "%20")
  return http:get(concat("http://where.yahooapis.com/v1/places.q(&apos;",$x,"&apos;)?appid=[",$shared:appid,"]"))
};

(:~
 : This function will find the woeid of a certain location.
 : @see http://developer.yahoo.com/geo/geoplanet/guide/api_docs.html#api_overview
 : @param $location string location for query
 : @return string Where On Earth ID
 :)
declare function yahoo:woeid($location as xs:string) as xs:string?
{
  let $result := yahoo:woeid-xml($location)//*:woeid
  return
    if(empty($result))
    then error($err:YS002, concat("Location not found: ", $location))
    else $result/data(.)
};

(:~
 : This function will find the longitude and latitude pair of a certain location.
 : @see http://developer.yahoo.com/geo/geoplanet/guide/api_docs.html#api_overview
 : @param $location string location for query
 : @return string "longitude, latitude", or error err:YS002 if location is not found
 :)
declare function yahoo:longitude-latitude($location as xs:string) as xs:string?
{
  let $centroid := yahoo:woeid-xml($location)//*:centroid
  let $longitude := $centroid/*:longitude/data(.)
  let $latitude := $centroid/*:latitude/data(.)
  return 
    if(empty($centroid))
    then error($err:YS002, concat("Location not found: ", $location))
    else concat($longitude, ", ", $latitude)
};

(:~
 : This function returns the xml response containing the geocode information for a search string.
 : More than one result may be returned.
 : @see http://developer.yahoo.com/geo/placefinder/
 : @param $location free-form string query location @see http://developer.yahoo.com/geo/placefinder/guide/requests.html#free-form-format
 : @param $flags string of concatenated characters that specify the data returned. @see http://developer.yahoo.com/geo/placefinder/guide/requests.html#flags-parameter
 : @return xml response containing geocode information for a given location
 :)
declare function yahoo:location-xml($location as xs:string, $flags as xs:string?)
{
  let $response := http:get(concat("http://where.yahooapis.com/geocode?location=",fn:encode-for-uri($location),"&amp;flags=",$flags))
  return
    if($response//*:Found/data(.) eq "0")
    then error($err:YS002, concat("Location not found: ", $location))
    else $response
};

(:~
 : This function is for convenience. It returns the xml response containing the geocode information for a search string.
 : More than one result may be returned.
 : @see http://developer.yahoo.com/geo/placefinder/
 : @param $params parameter elements containing location (required; location, woeid for example) and control parameters (optional)
: @return xml response containing geocode information for a given location
:)
declare function yahoo:location-xml($params as element()+)
{
  let $parameters := shared:normalization($params,'=',"&amp;","")
  let $href := concat("http://where.yahooapis.com/geocode?",$parameters)
  return http:get($href)
};

(:~
 : This function returns the xml response containing the geocode information for a search string.
 : More than one result may be returned.
 : @see http://developer.yahoo.com/geo/placefinder/
 : @param $woeid string Where On Earth ID @see http://developer.yahoo.com/geo/geoplanet/guide/concepts.html#woeids
 : @param $flags string of concatenated characters that specify the data returned. @see http://developer.yahoo.com/geo/placefinder/guide/requests.html#flags-parameter
 : @return xml response containing geocode information for a given location
 :)
declare function yahoo:geocode-xml($woeid as xs:string, $flags as xs:string?)
{
  let $response := http:get(concat("http://where.yahooapis.com/geocode?woeid=",fn:encode-for-uri($woeid),"&amp;flags=",$flags))
  return
    if($response//*:Found/data(.) eq "0")
    then error($err:YS002, concat("Location not found for woeid: ", $woeid))
    else $response
};
