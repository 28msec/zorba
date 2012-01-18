import module namespace x = "http://www.zorba-xquery.com/modules/xml";
import schema namespace opt = "http://www.zorba-xquery.com/modules/xml-options";

x:parse("<?xml version='1.0' encoding = 'UTF-8'?>
<atomic:root xmlns:atomic='http://www.w3.org/XQueryTest'>
<atomic:duration>P1Y2M3DT10H30M</atomic:duration>",
  <opt:options>
    <opt:parse-external-parsed-entity/>
  </opt:options>
)
