(: 
  Dataguide and scripting variables
:)
jsoniq version "1.0";

import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

ddl:create(xs:QName("sales"));
dml:insert-last(xs:QName("sales"),
  ( {
      "category" : { "category" : { "category" : { "category" : "value" } } }
    }
  )
);

variable $col := dml:collection(xs:QName("sales"));
while ($col instance of structured-item())
{
  $col := $col.category;
};
$col
