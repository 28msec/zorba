import module namespace x = "http://www.zorba-xquery.com/modules/xml";
import schema namespace opt = "http://www.zorba-xquery.com/modules/xml-options";
import schema namespace weather = "http://www.w3.org/test/weather" at "weather.xsd";

x:parse("<?xml version='1.0' encoding = 'UTF-8'?>
<weather:weather xmlns:weather='http://www.w3.org/test/weather' xmlns:xsi='http://www.w3.org/2001/XMLSchema-instance'>
  <weather:temperature>30</weather:temperature>
  <weather:precipitation>20</weather:precipitation>
</weather:weather>
",
  <opt:options>
    <opt:schema-validate opt:mode="lax"/>
  </opt:options>
)
