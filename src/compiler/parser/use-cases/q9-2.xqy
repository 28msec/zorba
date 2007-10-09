module namespace z="http://www.example.com/xq/zips";
import schema namespace ipo = "http://www.example.com/IPO" at "ipo.xsd";
import schema namespace zips = "http://www.example.com/zips" at "zips.xsd";

declare function z:zip-ok($a as element(*, ipo:USAddress))
  as xs:boolean
{ 
  some $i in doc("zips.xml")/zips:zips/element(zips:row)
  satisfies $i/zips:city = $a/city
        and $i/zips:state = $a/state
        and $i/zips:zip = $a/zip
 };
