(:~ 
: Google Services Module
: This module wraps a few of the Google APIs listed on <a href="http://www.programmableweb.com/search/google" target="_blank">http://www.programmableweb.com/search/google</a>
: @author Stephanie Russell
: @version 1.0
:)
module namespace google = 'http://www.zorba-xquery.com/modules/google_apis';
import module namespace http = "http://expath.org/ns/http-client";
(:~
 : Use err module functions for throwing errors.
 :)
import module namespace err="http://www.zorba-xquery.com/modules/errors";

(:~
: This function returns the xml response of a book search.
: @param $book string query for book search
: @param $start integer describing where to start the results
: @param $max integer describing where to end the results
: @return xml response describing book results close to query string $book.
:)
(:public:)
declare function google:book-search-xml($book as xs:string, $start as xs:integer?, $max as xs:integer?)
{
  let $query := fn:replace(fn:replace($book, "NOT ", "-"), " ","+")
  let $href := concat("http://books.google.com/books/feeds/volumes?q=",$query,
    if (empty($start))
    then ""
    else concat("&amp;start-index=",$start),
    if(empty($max))
    then ""
    else concat("&amp;max-results=",$max))
  return http:read($href)[2]
};

(:~
: This function returns the ISBN (and other identifying numbers) for a book.
: @param $book string query for book search
: @param $start integer describing where to start the results
: @param $max integer describing where to end the results
: @return response containing ISBNs for book query results close to query string $book.
:)
(:public:)
declare function google:ISBN($book as xs:string, $start as xs:integer?, $max as xs:integer?) as xs:string+
{
  let $response := google:book-search-xml($book, $start, $max)
  return
    if(xs:string($response//*:totalResults) eq "0")
    then error($err:GS002, concat("No book results found containing: ", $book))
    else
      for $isbn in $response//*:identifier/data(.)
      return ($isbn, "&#xA;")
};

(:~
: This function queries the youtube search api and returns the top 10 results for a search-string
: @param $developer-key key received in registering an application
: @param $search-term string describing the video requested
: @return xml response containing 10 youtube videos of closest match to query $search-term
:)
(:public:)
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
(:public:)
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
(:public:)
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
(:public:)
declare function google:youtube-category-search($category as xs:string) as xs:string+
{
  let $response := google:youtube-category-search-xml($category)
  for $x in $response[2]//@href
  return (data($x), "&#xA;")
};

(:~
: This function uses the Google Maps API to get directions from one location to another. One can also request
: to avoid tolls or highways.
: @param $from string starting location
: @param $to string final destination
: @param $avoid string (either tolls or highways) to avoid
: @return xml response containing the directions from one location to another.
:)
(:public:)
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
(:public:)
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
