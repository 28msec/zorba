<result>{
for $store in doc("stores.xml")/*/store
for $sale in doc("sales-records.xml")/*/record
where $store/store-number eq $sale/store-number
return 
  <store number="{$store/store-number}">{
    $sale
  }</store>
}</result>