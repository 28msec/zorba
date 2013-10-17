import module namespace ddl = "http://zorba.io/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/dynamic/collections/dml";
import module namespace j = "http://jsoniq.org/functions";

ddl:create(xs:QName("sales"));
ddl:create(xs:QName("products"));
ddl:create(xs:QName("stores"));

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

dml:insert-last(xs:QName("products"),
  (
    { "name" : "broiler", "category" : "kitchen", "price" : 100, "cost" : 70 },
    { "name" : "toaster", "category" : "kitchen", "price" : 30, "cost" : 10 },
    { "name" : "blender", "category" : "kitchen", "price" : 50, "cost" : 25 },
    { "name" : "socks", "category" : "clothes", "price" : 5, "cost" : 2 },
    { "name" : "shirt", "category" : "clothes", "price" : 10, "cost" : 3 }
  )
);

dml:insert-last(xs:QName("stores"),
  (
    { "store number" : 1, "state" : "CA" },
    { "store number" : 2, "state" : "CA" },
    { "store number" : 3, "state" : "MA" },
    { "store number" : 4, "state" : "MA" }
  )
);

{|
  for $store in dml:collection(xs:QName("stores"))
  let $state := $store("state")
  group by $state
  return 
    {
      $state : 
      {|
        for $product in dml:collection(xs:QName("products"))
        let $category := $product("category")
        group by $category
        return
          { 
            $category : 
            {|
              for $sales in dml:collection(xs:QName("sales"))
              where $sales("store number") = $store("store number")
                 and $sales("product") = $product("name")
              let $pname := $sales("product")
              group by $pname
              return { $pname : sum( $sales("quantity") ) }
            |}
          }
        |}
      }
|}
