declare variable $products_ctx external;

<page>{
for $product in doc($products_ctx)/*/product
order by $product
count $x
return 
<item pos="{$x}">{$product/name}</item>
}</page>
