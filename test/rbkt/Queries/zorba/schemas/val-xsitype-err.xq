import schema namespace 
  s = "http://www.zorba-xquery.com/simple.xsd" 
  at "simple.xsd";


validate
{
  <product xsi:type="HatType"  
       xmlns='http://www.zorba-xquery.com/simple.xsd' xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance">
    <name>hat product</name>
    <number>111</number>
    <size>14</size>
  </product>
}
