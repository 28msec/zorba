(:
  Dataguide for a object lookup that has two collection sources.
:)
jsoniq version "1.0";

import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

ddl:create(xs:QName("sales"));
dml:insert-last(xs:QName("sales"),
  ( { "product" :  { "name" : "broiler",
                     "price" : 100 
                   },
      "category1" : { "category3" :
                       { "category4" : "value4" }
                   } 
    }
  )
);

let $col := dml:collection(xs:QName("sales"))
let $col1 := $col.category1
let $col2 := $col.category2
let $col3 := ($col1, $col2)
return {
         $col3.category3
       }
