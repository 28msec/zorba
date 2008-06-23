import schema namespace 
  s = "simple.xsd" 
  at "simple.xsd";


validate
{
  <product xsi:type="HatType"  
       xmlns='simple.xsd' xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance">
    <name>hat product</name>
    <number>111</number>
    <size>7</size>
  </product>
}