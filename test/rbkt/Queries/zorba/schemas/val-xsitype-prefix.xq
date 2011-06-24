import schema namespace 
  s = "http://www.zorba-xquery.com/simple.xsd" 
  at "simple.xsd";


validate
{
  <p:product xsi:type="p:HatType"  
       xmlns:p='http://www.zorba-xquery.com/simple.xsd' xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance">
    <p:name>hat product</p:name>
    <p:number>111</p:number>
    <p:size>11</p:size>
  </p:product>
}
