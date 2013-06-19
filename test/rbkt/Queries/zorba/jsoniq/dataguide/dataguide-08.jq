jsoniq version "1.0";

import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";
import module namespace j = "http://jsoniq.org/functions";

ddl:create(xs:QName("sales"));

dml:insert-last(xs:QName("sales"),
  ( { "product" :  { "name" : "broiler",
                     "price" : 100 
                   },
      "category" : { "category2" :
                       { "category3" : "value3" },
                     "type" : "type1"   
                   } 
    }
  )
);

let $col := dml:collection(xs:QName("sales"))
let $col1 := $col.category 
where $col1.category2.category3 eq "value3"
return {
         $col1.category3,
         "foo"
       }
