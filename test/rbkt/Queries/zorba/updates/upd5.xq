import schema namespace s="http://www.zorba-xquery.org/schema" at "shiporder.xsd";

declare revalidation skip;

variable $x:=validate
{
<shiporders xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
            xmlns="http://www.zorba-xquery.org/schema">
<shiporder orderid="889923">
  <orderperson>John Smith</orderperson>
  <shipto>
    <name>Ola Nordmann</name>
    <address>Langgt 23</address>
    <city>4000 Stavanger</city>
    <country>Norway</country>
  </shipto>
  <item>
    <title>Empire Burlesque</title>
    <note>Special Edition</note>
    <quantity>1</quantity>
    <price>10.90</price>
  </item>
  <item>
    <title>Hide your heart</title>
    <quantity>1</quantity>
    <price>9.90</price>
  </item>
</shiporder>
</shiporders>
};

variable $z:=$x/*;

delete node $x/*;

format-number($z,"aa")
