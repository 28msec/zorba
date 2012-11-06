declare variable $sales :=
<sales>
<sale amount="1"><product id="1"/></sale>
<sale amount="5"><product id="2"/></sale>
<sale amount="7"><product id="2"/></sale>
<sale amount="3"><product id="1"/></sale>
</sales>;

for $sale at $pos in $sales/sale
let $prodid := $sale/product/@id
group by $prodid
where $pos = 3
return sum($sale/@amount)
