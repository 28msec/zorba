<result>{
for $product in doc("products.xml")
for $sales in doc("sales-records.xml")
where $sales/product-name eq $product/name
return 
  <store number="{$sales/store-number}">{
    $product
  }</store>
}</result>