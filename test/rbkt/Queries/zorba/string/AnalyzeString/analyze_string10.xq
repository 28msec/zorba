
import module namespace zorba-schema = "http://zorba.io/modules/schema";
import schema namespace xp = "http://www.w3.org/2005/xpath-functions";

let $result := fn:analyze-string(
"abab
babba", "(b)a", "m")
return 
 ($result, "
 ",
 zorba-schema:is-validated($result))