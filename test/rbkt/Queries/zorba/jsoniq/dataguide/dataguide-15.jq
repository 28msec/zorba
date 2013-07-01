(:
  Dataguide and group by clauses: simple case
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
for $p in (100,200,300)
group by $price := $col.category1.price
return (
         $p, 
         $price
       )
