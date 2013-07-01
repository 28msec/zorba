(:
  Dataguide in combination with the jsoniq:keys() function
:)
jsoniq version "1.0";

import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

ddl:create(xs:QName("sales"));
dml:insert-last(xs:QName("sales"),
  ( { "category1" : { "name" : "broiler",
                      "price" : 200},
                      
      "category2" : { "name" : "food",
                      "price" : 200},
                      
      "category3" : { "name" : "beverage",
                      "price" : 100} 
    }
  )
);


let $col := dml:collection(xs:QName("sales"))
for $var in keys($col.category1)
return { 
         $var,
         $col.category1.name
       }
