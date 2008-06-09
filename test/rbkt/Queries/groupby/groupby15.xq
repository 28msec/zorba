declare variable $sales-records external;
declare variable $stores external;
declare variable $products external;
<result>{
  for $sales in doc($sales-records)/*/record
  let $state := doc($stores)/*/store[store-number = $sales/store-number]/state,
    $product := doc($products)/*/product[name = $sales/product-name],
    $category := $product/category,
    $revenue := $sales/qty * $product/price
  group by $state, $category
  order by $state, $category
  return
    <group>
      {$state, $category}
      <total-revenue>{sum($revenue)}</total-revenue>
    </group> 
}</result>
