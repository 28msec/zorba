import schema namespace ipo="http://www.example.com/IPO" at "ipo.xsd";

declare function local:comment-text($c as schema-element(ipo:comment))
  as xs:string
{
    xs:string( $c )
};

for $p in doc("ipo.xml")/schema-element(ipo:purchaseOrder)
where $p/shipTo/name="Helen Zoe"
  and $p/@orderDate = xs:date("1999-12-01")
return local:comment-text( $p//ipo:customerComment )
