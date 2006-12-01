import schema namespace ipo="http://www.example.com/IPO" at "ipo.xsd";

declare function local:names-match( $s as element(shipTo, ipo:Address), 
                                    $b as element(billTo, ipo:Address))
  as xs:boolean
{
     $s/name = $b/name
};

let $p := doc("ipo.xml")/element(ipo:purchaseOrder)
return local:names-match( $p/shipTo, $p/billTo )
