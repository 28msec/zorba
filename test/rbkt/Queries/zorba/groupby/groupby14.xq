declare variable $sales-records external;
declare variable $stores external;
declare variable $products external;
<result>{ 
  for $sales in doc($sales-records)/*/record
  let $state := doc($stores)/*/store[store-number = $sales/store-number]/state
  let $category := doc($products)/*/product[name = $sales/product-name]/category
  group by $state, $category
  order by $state, $category
  return
    <group>
      {$state, $category}
      <total-qty>{sum($sales/qty)}</total-qty>
    </group>
}</result>
