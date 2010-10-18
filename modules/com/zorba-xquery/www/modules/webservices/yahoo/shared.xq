(:~
 : Yahoo Module for the commons
 : This module wraps a set of functions used by other Yahoo modules.
 : @author Stephanie Russell
 :
 :)

module namespace yahoo = 'http://www.zorba-xquery.com/modules/webservices/yahoo/shared';

(:~
 : Application ID
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
declare function yahoo:normalization($params as element()+, $divide as xs:string, $option as xs:string?,$comma as xs:string) as xs:string
{
  fn:string-join(
          for $param in $params//param
          let $k := $param/@key/data(.)
          let $v := $param/@value/data(.)
          return concat(fn:encode-for-uri($k), $divide,encode-for-uri($v), $option),$comma)
};
