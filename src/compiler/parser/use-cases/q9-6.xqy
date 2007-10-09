import schema namespace ipo="http://www.example.com/IPO" at "ipo.xsd";

let $p := doc("ipo.xml")//element(ipo:purchaseOrder)
let $billTo := $p/billTo
let $shipTo := $p/shipTo
return
   if ($billTo instance of element(*, ipo:USAddress))
     then every $i in $p/items/item 
              satisfies (exists($i/USPrice))
         else false()
