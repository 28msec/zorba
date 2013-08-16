import module namespace x = "http://zorba.io/modules/xml";
import schema namespace opt = "http://zorba.io/modules/xml-options";
import schema namespace weather = "http://www.w3.org/test/weather" at "weather.xsd";

x:parse("<?xml version='1.0' encoding = 'UTF-8'?>
<weather:weather xmlns:weather='http://www.w3.org/test/weather' xmlns:xsi='http://www.w3.org/2001/XMLSchema-instance'>
  <weather:incorrect>30</weather:incorrect>
  <weather:precipitation>20</weather:precipitation>
</weather:weather>
",
  <opt:options>
    <opt:schema-validate opt:mode="strict"/>
  </opt:options>
)

