(:~
 : Google YouTube Services Module
 : This module wraps a few of the Google YouTube APIs listed on <a href="http://code.google.com/apis/youtube/overview.html" target="_blank">http://code.google.com/apis/youtube/overview.html</a>
 : @author Stephanie Russell
 : @version 1.0
 :)

module namespace google = 'http://www.zorba-xquery.com/modules/web-services/google/youtube';
import module namespace http = "http://expath.org/ns/http-client";

(:~
 : This function queries the youtube search api and returns the top 10 results for a search-string
 : @param $developer-key key received in registering an application
 : @param $search-term string describing the video requested
 : @return xml response containing 10 youtube videos of closest match to query $search-term
 :)
declare function google:youtube-search-xml($developer-key as xs:string, $search-term as xs:string)
{
  let $video := fn:encode-for-uri($search-term)
  let $href := concat("http://gdata.youtube.com/feeds/api/videos?q=",$video,"&amp;max-results=10","&amp;key=",$developer-key)
  return http:read($href)
};

(:~
 : This function returns strings containing the uri's of the query string.
 : @param $developer-key key received in registering an application
 : @param $search-term string describing the video requested
 : @return string urls to video found by the query $search-term
 :)
declare function google:youtube-search($developer-key as xs:string,$search-term as xs:string) as xs:string+
{
  let $response := google:youtube-search-xml($developer-key,$search-term)
  for $x in $response//*:player/@url
  return (data($x), "&#xA;")
};

(:~
 : This function returns the xml response of a category query.
 : @param $category string describing the category (genre) of videos desired
 : @return xml response of the category request
 :)
declare function google:youtube-category-search-xml($category as xs:string)
{
  let $href := concat("http://gdata.youtube.com/feeds/api/videos/-/", fn:encode-for-uri($category))
  return http:read($href)
};

(:~
 : This function returns the hrefs to the results of the category query.
 : @param $category string describing the category (genre) of videos desired
 : @return string hrefs of the category request
 :)
declare function google:youtube-category-search($category as xs:string) as xs:string+
{
  let $response := google:youtube-category-search-xml($category)
  for $x in $response[2]//@href
  return (data($x), "&#xA;")
};