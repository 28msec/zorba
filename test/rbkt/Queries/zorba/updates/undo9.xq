import module namespace m = 'xqueryzorba.org/test/xqddf/ic' at '../xqddf/ic.xqlib';
import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";
import module namespace ic_ddl = "http://zorba.io/modules/store/static/integrity-constraints/ddl";
import module namespace schema = "http://zorba.io/modules/schema";
import module namespace u = "http://www.zorba-xquery.com/test/undo/utils" at "utils.xqlib";
import schema namespace s="http://www.zorba-xquery.org/schema" at "shiporder.xsd";

declare revalidation lax;
declare construction strip;

variable $x:=
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
</shiporders>;


ddl:create($m:empc);

ic_ddl:activate(xs:QName("m:ic_simple"));

try
{
(   
  insert node ($x//*:item)[1]/*:note after ($x//*:item)[last()]/*:title,  

  dml:insert($m:empc, <emp><salary>600</salary></emp>)
);
}
catch *
{
}

u:dump-types($x)
