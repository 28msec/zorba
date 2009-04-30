declare variable $sales_ctx external;
declare variable $products_ctx external;

for $sales in doc($sales_ctx)/*/record
for $product in doc($products_ctx)/*/product
where $product/name eq $sales/product-name
let $order-price := $product/price * $sales/qty
order by $order-price descending
count $x
where $x < 5
return 
<sale product="{$product/name}" amount="{$order-price}"/>
