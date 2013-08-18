import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

declare variable $test external := 1;

ddl:create(xs:QName("sales"));
dml:insert-last(xs:QName("sales"),
  ( { "product" : { "name" : "broiler",
                     "price" : 100
                   },
      "category1" : { "category3" :
                       { "category4" : "value4" }
                   }
    }
  )
);

(exactly-one(
  if ($test)
  then
   dml:collection(xs:QName("sales"))[1]
  else
   dml:collection(xs:QName("sales"))[2]
)).category1
