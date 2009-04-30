declare variable $sales_ctx external;
declare variable $products_ctx external;

for $sales in doc($sales_ctx)/*/record
for $product in doc($products_ctx)/*/product
where $product/name eq $sales/product-name
let $order-price := $product/price * $sales/qty
let $product-price := $product/price
group by $order-price, $product-price
order by $order-price descending
count $x
where $x < 5
return 
<sale amount="{$order-price}"><products>{$product/name}</products></sale>

(:

<sale amount="7500"><products><name>blender</name></products></sale>
<sale amount="5000"><products><name>blender</name></products></sale>
<sale amount="3000"><products><name>toaster</name></products></sale>
<sale amount="2500"><products><name>socks</name></products></sale>

:)
