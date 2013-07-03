(:
  Dataguide and UDFs:
  recursive function -- dataguide past the function call is "*"
:)
jsoniq version "1.0";

import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

declare function local:nav($var)
{
  if ($var instance of structured-item())
  then ($var.category, local:nav($var.category) )
  else "Done."
};


ddl:create(xs:QName("sales"));
dml:insert-last(xs:QName("sales"),
  ( { "product" :  { "name" : "broiler",
                     "price" : 100 
                   },
      "category" : { "category" : { "category" : { "category" : "value" } } }
    }
  )
);


let $col := dml:collection(xs:QName("sales"))
return {
         local:nav($col.category)
       }
