(:
  Dataguide and fn:count(): 
  fn:count() does not explore JSON objects so it does not introduce
  new restrictions in the computed dataguide
:)
jsoniq version "1.0";

import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

ddl:create(xs:QName("sales"));
dml:insert-last(xs:QName("sales"),
  ( { {"id" : "1", "price": 100 },
      {"id" : "2", "price": 100 },
      {"id" : "3"}
    }
  )
);

for $col in dml:collection(xs:QName("sales"))
group by $price := $col.price
return {
         price: $price,
         count: count($col)
       }
