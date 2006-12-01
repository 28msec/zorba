import schema namespace ipo="http://www.example.com/IPO" at "ipo.xsd";

declare function local:deadbeat( $b as element(billTo, ipo:USAddress) )
  as xs:boolean
{
   $b/name = doc("deadbeats.xml")/deadbeats/row/name
}; 

for $p in doc("ipo.xml")//element(ipo:purchaseOrder)
where local:deadbeat( $p/element(billTo) )
return <warning>{ string($p/billTo/name) } is a known deadbeat!</warning>
