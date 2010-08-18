 (:~ 
  : Yahoo Services Module
  : This module wraps many of the Yahoo! APIs listed on <a href="http://www.programmableweb.com/search/yahoo" target="_blank">http://www.programmableweb.com/search/yahoo</a>.
  : @author Stephanie Russell
  : @version 1.0
  :)

module namespace yahoo = 'http://www.zorba-xquery.com/modules/yahoo_apis';
import module namespace http = "http://expath.org/ns/http-client";
(:~
 : Use err module functions for throwing errors.
 :)
import module namespace err="http://www.zorba-xquery.com/modules/errors";

 (:~
  :Application ID
  :)
declare variable $yahoo:appid as xs:string:="UycaMUTV34EdWHmbojYbqY1Pq888ZRlP3tePPp.1G0G2g2LhkW9PU7HWnY.JJh7L.XA-";
(:declare assignable variable $yahoo:appid as xs:string:=external;:)

(:~
: This function normalizes parameters into a single string.
: @param $params Parameter elements
: @param $divide String, usually an equal sign (=)
: @param $option Optional string, typically an ampersand (&amp;)
: @param $comma String separator
: @return string parameters formatted specifically for a yahoo api service request
:)

(:private:)
declare function yahoo:normalization($params as element()+, $divide as xs:string, $option as xs:string?,$comma as xs:string) as xs:string
{ 
  fn:string-join(
          for $param in $params//param
          let $k := $param/@key/data(.)
          let $v := $param/@value/data(.)
          return concat(fn:encode-for-uri($k), $divide,encode-for-uri($v), $option),$comma)
};

(:~
: This function will return the xml response of a query for an alternate spelling of $word.
: @param $word string query for correct spelling
: @return (xml) response
:)
(:public:)
declare function yahoo:spelling-xml($word as xs:string)
{
  http:read(concat("http://search.yahooapis.com/WebSearchService/V1/spellingSuggestion?appid=",$yahoo:appid,"&amp;query=", $word))
};
(:~
: This function will return alternate spelling for a $word string query, or an error if not found.
: @param $word string query for correct spelling
: @return string correct spelling or an error if there is not alternative spelling found
:)
(:public:)
declare function yahoo:spelling($word as xs:string) as xs:string?
{
  let $response := yahoo:spelling-xml($word)
  let $result := $response[2]//*:Result
  let $spelling :=
    if (empty($result))
    then error($err:YS001, concat("No alternative spelling found for: ", $word))
    else $result/data(.)
  return $spelling
};
(:~
: This function will return the xml response of the query for a $location.
: @see http://developer.yahoo.com/geo/geoplanet/guide/api_docs.html#api_overview
: @param $location string location for query
: @return xml response including longitude, latitude, and woeid.
:)
(:public:)
declare function yahoo:woeid-xml($location as xs:string)
{
  let $x := fn:replace($location, " ", "%20")
  return http:read(concat("http://where.yahooapis.com/v1/places.q(&apos;",$x,"&apos;)?appid=[",$yahoo:appid,"]"))
};
(:~
: This function will find the woeid of a certain location.
: @see http://developer.yahoo.com/geo/geoplanet/guide/api_docs.html#api_overview
: @param $location string location for query
: @return string Where On Earth ID
:)
(:public:)
declare function yahoo:woeid($location as xs:string) as xs:string?
{
  let $result :=yahoo:woeid-xml($location)//*:woeid
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
(:public:)
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
: This function will return the xml response weather statement of a query $location
: @see http://developer.yahoo.com/weather/
: @param $location string location for query
: @return xml response of the weather forecast for a given location
:)
(:public:)
declare function yahoo:weather-xml($location as xs:string)
{
  let $woeid := yahoo:woeid($location)
  let $href := fn:concat("http://weather.yahooapis.com/forecastrss?w=",$woeid, "&amp;u=f")
  return http:read($href)
};

(:~
: This function is for convenience. It will return the xml response weather statement of a query $location
: @see http://developer.yahoo.com/weather/
: @param $params parameter elements containing woeid (required) and optional units ('f' or 'c')
: @return xml response of the weather forecast for a given location
:)
(:public:)
declare function yahoo:weather-params-xml($params as element()+)
{
  let $parameters := yahoo:normalization($params,'=',"&amp;","")
  let $href := concat("http://weather.yahooapis.com/forecastrss?",$parameters)
  return http:read($href)
};
(:~
: This function will return the weather for a query location.
: @see http://developer.yahoo.com/weather/
: @param $location string location for query
: @return weather forecast
:)
(:public:)
declare function yahoo:weather($location as xs:string) as xs:string+
{
  let $weather := yahoo:weather-xml($location)[2]//*:description/data(.)
  for $report in $weather 
  return fn:replace($report, "&lt;.*&gt;", "")
};

(:~
: This function will return the xml response for a traffic report query.
: @see http://developer.yahoo.com/traffic/rest/V1/index.html
: @param $location string location for query
: @return xml response of the traffic for a given location
:)
(:public:)
declare function yahoo:traffic-report-xml($location as xs:string)
{
  let $href := concat("http://local.yahooapis.com/MapsService/V1/trafficData?appid=",$yahoo:appid,"&amp;location=",fn:encode-for-uri($location),"&amp;include_map=1")
  return http:read($href)
};

(:~
: This function is for convenience. It will return the xml response for a given location.
: @see http://developer.yahoo.com/traffic/rest/V1/index.html
: @param $params parameter elements containing location (required as first element) and other optional parameters
: @return xml response of the traffic for a given location
:)
(:public:)
declare function yahoo:traffic-report-params-xml($params as element()+)
{
  let $parameters := yahoo:normalization($params,'=',"&amp;","")
  let $href := concat("http://local.yahooapis.com/MapsService/V1/trafficData?appid=",$yahoo:appid,"&amp;",$parameters)
  return http:read($href)
};
(:~
: This function will return the traffic report for a given location
: @see http://developer.yahoo.com/traffic/rest/V1/index.html
: @param $location string location for query
: @return traffic report
:)
(:public:)
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

(:~
: This function will return the xml response for a map query.
: @see http://developer.yahoo.com/maps/rest/V1/index.html
: @param $location string location for query
: @return xml response of the map url for a given location
:)
(:public:)
declare function yahoo:map-xml($location as xs:string)
{
  let $newLocation := fn:replace($location, " ", "+")
  return http:read(concat("http://local.yahooapis.com/MapsService/V1/mapImage?appid=",$yahoo:appid,"&amp;location=", $newLocation))
};

(:~
: This function is for convenience. It will return the xml response of a map for a given location.
: @see http://developer.yahoo.com/maps/rest/V1/index.html
: @param $params parameter elements containing location (required as first element) and other optional parameters
: @return xml response of the map for a given location
:)
(:public:)
declare function yahoo:map-params-xml($params as element()+)
{
  let $parameters := yahoo:normalization($params,'=',"&amp;","")
  let $href := concat("http://local.yahooapis.com/MapsService/V1/mapImage?appid=",$yahoo:appid,"&amp;",$parameters)
  return http:read($href)
};

(:~
: This function will return the url for a map of the location query.
: @see http://developer.yahoo.com/maps/rest/V1/index.html
: @param $location string location for query
: @return the map url for a given location
:)
(:public:)
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
(:~
: This function returns the xml response containing the geocode information for a search string.
: More than one result may be returned.
: @see http://developer.yahoo.com/geo/placefinder/
: @param $location free-form string query location @see http://developer.yahoo.com/geo/placefinder/guide/requests.html#free-form-format
: @param $flags string of concatenated characters that specify the data returned. @see http://developer.yahoo.com/geo/placefinder/guide/requests.html#flags-parameter
: @return xml response containing geocode information for a given location
:)
(:public:)
declare function yahoo:location-xml($location as xs:string, $flags as xs:string?)
{
  let $response := http:read(concat("http://where.yahooapis.com/geocode?location=",fn:encode-for-uri($location),"&amp;flags=",$flags))
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
(:public:)
declare function yahoo:location-xml($params as element()+)
{
  let $parameters := yahoo:normalization($params,'=',"&amp;","")
  let $href := concat("http://where.yahooapis.com/geocode?",$parameters)
  return http:read($href)
};

(:~
: This function returns the xml response containing the geocode information for a search string.
: More than one result may be returned.
: @see http://developer.yahoo.com/geo/placefinder/
: @param $woeid string Where On Earth ID @see http://developer.yahoo.com/geo/geoplanet/guide/concepts.html#woeids
: @param $flags string of concatenated characters that specify the data returned. @see http://developer.yahoo.com/geo/placefinder/guide/requests.html#flags-parameter
: @return xml response containing geocode information for a given location
:)
(:public:)
declare function yahoo:geocode-xml($woeid as xs:string, $flags as xs:string?)
{
  let $response := http:read(concat("http://where.yahooapis.com/geocode?woeid=",fn:encode-for-uri($woeid),"&amp;flags=",$flags))
  return
    if($response//*:Found/data(.) eq "0")
    then error($err:YS002, concat("Location not found for woeid: ", $woeid))
    else $response
};
