import schema namespace 
  s = "http://www.zorba-xquery.com/simple.xsd" 
  at "simple.xsd";


validate strict
{
  <product xsi:type="ShirtType"  
      xmlns="http://www.zorba-xquery.com/simple.xsd" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance">
    <name>shirt product</name>
    <number>13221</number>
    <size>XL</size>
    <color>red</color>
  </product>
}
