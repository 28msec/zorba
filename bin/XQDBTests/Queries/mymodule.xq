module namespace shopping = "http://www.zorba-xquery.com/shopping";

declare function shopping:discount($price as xs:decimal?, $discount as xs:decimal?) as xs:decimal?
{
  let $disc := ($price*$discount) div 100
  return ($price - $disc)
};
