(: 
  Dataguide and if expressions
:)
jsoniq version "1.0";

import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

ddl:create(xs:QName("sales"));
dml:insert-last(xs:QName("sales"),
  ( {
      "category" : { category2 : "value" }
    }
  )
);

let $col := dml:collection(xs:QName("sales"))
return if ($col.category.category2)
       then $col.category
       else ()
