(:~
 : Google Maps Services Module
 : This module wraps a few of the Google Maps APIs listed on <a href="http://code.google.com/apis/maps/index.html" target="_blank">http://code.google.com/apis/maps/index.html</a>
 : @author Stephanie Russell
 : @version 1.0
 :)

module namespace google = 'http://www.zorba-xquery.com/modules/web-services/google/maps';
import module namespace http = "http://expath.org/ns/http-client";

(:~
 : Use err module functions for throwing errors.
 :)
import module namespace err="http://www.zorba-xquery.com/modules/web-services/google/errors-maps";

(:~
 : This function uses the Google Maps API to get directions from one location to another. One can also request
 : to avoid tolls or highways.
 : @param $from string starting location
 : @param $to string final destination
 : @param $avoid string (either tolls or highways) to avoid
 : @return xml response containing the directions from one location to another.
 :)
declare function google:directions-xml($from as xs:string, $to as xs:string, $avoid as xs:string?)
{
  let $from := fn:replace($from, " ", "+")
  let $to := fn:replace($to, " ", "+")
  let $avoid-me :=if($avoid eq "tolls")
    then concat("&amp;avoid=",$avoid)
    else if($avoid eq "highways")
         then concat("&amp;avoid=",$avoid)
         else ""
  let $href := concat("http://maps.google.com/maps/api/directions/xml?origin=",$from,"&amp;destination=",$to,$avoid-me,"&amp;sensor=false")
  let $response := http:read($href)
  let $status := $response//*:status
  return
    if($status ne "OK")
    then error($err:GS001, concat("Invalid request: ", $status))
    else $response
};

(:~
 : This function uses the Google Maps API to get directions from one location to another. One can also request
 : to avoid tolls or highways. This is formatted to show time/distance on a certain road, ramps, and turns.
 : @param $from string starting location
 : @param $to string final destination
 : @param $avoid string (either tolls or highways) to avoid
 : @return the directions from one location to another.
 :)
declare function google:directions($from as xs:string, $to as xs:string, $avoid as xs:string?) as xs:string+
{
  let $response := google:directions-xml($from, $to, $avoid)[2]
  for $step in $response//step
  let $duration := $step//text/data(.)
  let $instruction := $step//html_instructions/data(.)
  let $direction := fn:replace(fn:replace($instruction, "&lt;b&gt;", ""),"&lt;/b&gt;","")
  let $new-direction := fn:replace(fn:replace($direction,"&lt;div style=""font-size:0.9em""&gt;",", "),"&lt;/div&gt;",".")
  return ($duration, "&#xA;", $new-direction,"&#xA;")
};
