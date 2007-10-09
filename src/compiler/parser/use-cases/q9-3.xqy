module namespace p="http://www.example.com/xq/postals";
import schema namespace ipo = "http://www.example.com/IPO" at "ipo.xsd";
import schema namespace pst = "http://www.example.com/postals" at "postals.xsd";

declare function p:postal-ok($a as element(*, ipo:UKAddress))
  as xs:boolean
{
  some $i in doc("postals.xml")/pst:postals/element(pst:row)
  satisfies $i/pst:city = $a/city
       and starts-with($a/postcode, $i/pst:prefix)
};
