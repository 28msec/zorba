jsoniq version "1.0";

import module namespace refl = "http://www.zorba-xquery.com/modules/reflection";
import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";
import module namespace j = "http://jsoniq.org/functions";

ddl:create(xs:QName("sales"));
dml:insert-last(xs:QName("sales"),
  ( { "product" :  { "name" : "broiler",
                     "price" : 100 
                   },
      "category" : { "category2" :
                       { "category3" : "value3" }
                   } 
    }
  )
);


let $col := dml:collection(xs:QName("sales"))
return {
         $col.category,
         refl:eval("$col") 
       }
