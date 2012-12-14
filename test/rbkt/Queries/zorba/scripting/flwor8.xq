declare variable $gid as xs:integer := 0;

<result>
{ 
  for $sales in doc("sales-records.xml")/*/record
  let $state := doc("stores.xml")/*/store[store-number = $sales/store-number]/state
  let $category := doc("products.xml")/*/product[name = $sales/product-name]/category
  group by $state, $category
  return
  {
    $gid := $gid + 1;

    <group id = "{$gid}">
      <state>{$state}</state><category>{$category}</category>
      <total-qty>{sum($sales/qty)}</total-qty>
    </group>
  }
}
</result>
