declare variable $sales-records external;
declare variable $products external;
<result>{
  for $sales in doc($sales-records)/*/record
  let $storeno := $sales/store-number,
    $product := doc($products)/*/product[name = $sales/product-name],
    $prd := $product,
    $profit := $sales/qty * ($prd/price - $prd/cost)
  group by $storeno
  let $total-store-profit := sum($profit)
  where $total-store-profit > 100
  order by $total-store-profit descending
  return
    <store number = "{$storeno}" total-profit = "{$total-store-profit}"/> 
 }</result>
