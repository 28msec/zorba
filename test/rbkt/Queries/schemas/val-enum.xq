import schema namespace 
  s = "simple.xsd" 
  at "simple.xsd";


validate strict
{
  <product xsi:type="ShirtType"  
      xmlns="simple.xsd" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance">
    <name>shirt product</name>
    <number>13221</number>
    <size>XL</size>
    <color>red</color>
  </product>
}
