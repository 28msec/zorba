declare construction strip;

import schema namespace ft =  "http://www.zorba-xquery.com/modules/full-text";
import module namespace schema = "http://www.zorba-xquery.com/modules/schema";

let $x := validate {<ft:compare-options 
                           case="case sensitive" 
                           diacritics="diacritics sensitive"
                           stemming="stemming"/>}
let $y:= (<a> { $x } </a>)/*
return 
   schema:schema-type($y/@case)
