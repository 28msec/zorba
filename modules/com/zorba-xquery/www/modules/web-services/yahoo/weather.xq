(:~
 : Yahoo! Weather Module
 : This module wraps many of the Yahoo! Weather APIs listed on <a href="http://developer.yahoo.com/weather/" target="_blank">http://developer.yahoo.com/weather/</a>.
 : @author Stephanie Russell
 : @version 1.0
 :)

module namespace yahoo = 'http://www.zorba-xquery.com/modules/web-services/yahoo/weather';
import module namespace http = "http://expath.org/ns/http-client";

(:~
 : This function will return the xml response weather statement of a query $location
 : @see http://developer.yahoo.com/weather/
 : @param $location string location for query
 : @return xml response of the weather forecast for a given location
 :)
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
declare function yahoo:weather($location as xs:string) as xs:string+
{
  let $weather := yahoo:weather-xml($location)[2]//*:description/data(.)
  for $report in $weather 
  return fn:replace($report, "&lt;.*&gt;", "")
};
