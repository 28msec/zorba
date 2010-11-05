(:~
 : Yahoo! Search Services Module
 : This module wraps many of the Yahoo! Search APIs listed on <a href="http://developer.yahoo.com/search/web/webSearch.html" target="_blank">http://developer.yahoo.com/search/web/webSearch.html</a>.
 : @author Stephanie Russell
 : @see <a href="http://developer.yahoo.com/search/web/webSearch.html" target="_blank">http://developer.yahoo.com/search/web/webSearch.html</a>
 :
 :)

module namespace yahoo = 'http://www.zorba-xquery.com/modules/webservices/yahoo/search';
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
 : This function will return the xml response of a query for an alternate spelling of $word.
 : @see http://developer.yahoo.com/search/web/V1/spellingSuggestion.html
 : @param $word string query for correct spelling
 : @return (xml) response
 :)
declare function yahoo:spelling-xml($word as xs:string)
{
  http:get(concat("http://search.yahooapis.com/WebSearchService/V1/spellingSuggestion?appid=",$shared:appid,"&amp;query=", $word))
};

(:~
 : This function will return alternate spelling for a $word string query, or an error if not found.
 : @see http://developer.yahoo.com/search/web/V1/spellingSuggestion.html
 : @param $word string query for correct spelling
 : @return string correct spelling or an error if there is not alternative spelling found
 :)
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
