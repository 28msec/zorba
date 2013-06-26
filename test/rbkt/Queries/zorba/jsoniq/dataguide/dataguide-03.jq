jsoniq version "1.0";

import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

ddl:create(xs:QName("sales"));
dml:insert-last(xs:QName("sales"),
  (
    { "product" : "broiler", "store number" : 1, "quantity" : 20  },
    { "product" : "toaster", "store number" : 2, "quantity" : 100 },
    { "product" : "toaster", "store number" : 2, "quantity" : 50 },
    { "product" : "toaster", "store number" : 3, "quantity" : 50 },
    { "product" : "blender", "store number" : 3, "quantity" : 100 },
    { "product" : "blender", "store number" : 3, "quantity" : 150 },
    { "product" : "socks", "store number" : 1, "quantity" : 500 },
    { "product" : "socks", "store number" : 2, "quantity" : 10 },
    { "product" : "shirt", "store number" : 3, "quantity" : 10 }
  )
);

ddl:create(xs:QName("sales2"));
dml:insert-last(xs:QName("sales2"),
  (
    { "product" : "broiler", "store number" : 1, "quantity" : 20  },
    { "product" : "toaster", "store number" : 2, "quantity" : 100 },
    { "product" : "toaster", "store number" : 2, "quantity" : 50 },
    { "product" : "toaster", "store number" : 3, "quantity" : 50 },
    { "product" : "blender", "store number" : 3, "quantity" : 100 },
    { "product" : "blender", "store number" : 3, "quantity" : 150 },
    { "product" : "socks", "store number" : 1, "quantity" : 500 },
    { "product" : "socks", "store number" : 2, "quantity" : 10 },
    { "product" : "shirt", "store number" : 3, "quantity" : 10 }
  )
);


let $col := (dml:collection(xs:QName("sales")), dml:collection(xs:QName("sales2")))
return $col."product"
