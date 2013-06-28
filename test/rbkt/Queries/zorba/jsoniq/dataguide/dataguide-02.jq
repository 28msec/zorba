jsoniq version "1.0";

import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

ddl:create(xs:QName("sales"));
dml:insert-last(xs:QName("sales"),
  ( { "product" :  { "name" : "broiler",
                     "price" : 100 
                   },
      "category" : { "name" : "food" } 
    }
  )
);

ddl:create(xs:QName("sales2"));
dml:insert-last(xs:QName("sales2"),
  ( { "product" : { "name" : "toaster", 
                    "price" : "150"                    
                  } 
    }
  )
);

let $col := (dml:collection(xs:QName("sales")), dml:collection(xs:QName("sales2"))  )
return {
         $col.product.price,
         $col.category.name
       }
