import schema namespace 
  s = "simple.xsd" 
  at "simple.xsd";


validate strict
{
	<items xmlns="simple.xsd" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
	  xsi:schemaLocation="simple.xsd simple.xsd">
	  <product>
	    <name>Generic product</name>
	    <number>1</number>
	  </product>
	  <product xsi:type="ShirtType">
	    <name>shirt product</name>
	    <number>13221</number>
	    <size>XL</size>
	    <color>red</color>
	  </product>
	  <product xsi:type="HatType">
	    <name>hat product</name>
	    <number>4654</number>
	    <size>10</size>
	    <size>7</size>
	    <size>11</size>
	  </product>
	</items>
}
