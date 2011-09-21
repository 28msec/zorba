<result>{
for $product in doc("products.xml")/*/product
for $store in doc("stores.xml")/*/store
for $sale in doc("sales-records.xml")/*/record[
     store-number eq $store/store-number and product-name eq $product/name]
return 
  <store number="{$store/store-number}" product="{$sale/product-name}" sold="{$sale/qty}"/>
}</result>