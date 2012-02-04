import module namespace ddl = "http://www.zorba-xquery.com/modules/store/jsoniq/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/jsoniq/dynamic/collections/dml";
import module namespace j = "http://www.jsoniq.org/functions";

ddl:create(xs:QName("sales"));

dml:insert-nodes-last(xs:QName("sales"),
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

object {
  for $sales in dml:collection(xs:QName("sales"))
  let $pname := $sales("product")
  group by $pname
  return pair { $pname : sum(for $s in $sales return $s("quantity")) }
}
