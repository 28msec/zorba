(: 
  Dataguide and UDFs:
  UDF with two parameters that have the same source
:)
jsoniq version "1.0";

import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

declare function local:nav($var1, $var2)
{
  $var1.category2,
  $var2.category1
};


ddl:create(xs:QName("sales"));
dml:insert-last(xs:QName("sales"),
  ( { "product" :  { "name" : "broiler",
                     "price" : 100 
                   },
      "category" : { "category1" :
                       { "category2" : "value3" }
                   } 
    }
  )
);


let $col := dml:collection(xs:QName("sales"))
return {
         local:nav($col, $col.category)
       }
