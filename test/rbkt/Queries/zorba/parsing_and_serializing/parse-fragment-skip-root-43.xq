import module namespace z = "http://www.zorba-xquery.com/modules/xml";
import schema namespace opt = "http://www.zorba-xquery.com/modules/xml-options";

z:parse("<?xml version='1.0'?>
<n1:root xmlns:n1='ns' xmlns:m1='ms'><n2:root2 xmlns:n2='ns2' xmlns:m2='ms2'><n1:from1 xmlns:n3='ns3'><from2>Text from2</from2></n1:from1></n2:root2></n1:root>", 
  <opt:options>
    <opt:parse-external-parsed-entity opt:skip-root-nodes="3"/>
  </opt:options>
)
