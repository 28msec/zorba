<result>{
for $product in doc("products.xml")/*/product
for $sales in doc("sales-records.xml")/*/record
where $sales/product-name eq $product/name
return 
  <store number="{$sales/store-number}">{
    $product
  }</store>
}</result>