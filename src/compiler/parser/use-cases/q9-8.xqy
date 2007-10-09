import schema namespace ipo="http://www.example.com/IPO" at "ipo.xsd";

for $p in doc("ipo.xml")//element(ipo:purchaseOrder)
where $p/shipTo/name="Helen Zoe"
  and $p/@orderDate = xs:date("1999-12-01")
return $p//schema-element(ipo:comment)
