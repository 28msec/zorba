(:
  Dataguide and UDFs:
  two UDFs where the second one invokes the first one, with the order
  of parameters reversed.
:)
jsoniq version "1.0";

import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

declare function local:nav1($var1, $var2)
{
  $var1.category1,
  $var2.category2
};

declare function local:nav2($var1, $var2)
{
  local:nav1($var2, $var1)
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
         local:nav2($col, $col.category)
       }
