
import module namespace zorba-schema = "http://www.zorba-xquery.com/modules/schema";
import schema namespace xp = "http://www.w3.org/2005/xpath-functions";

let $result := fn:analyze-string(
"abab
babba", "(b)a", "m")
return 
 if(zorba-schema:is-validated($result)) then
   $result
 else
   validate{$result}