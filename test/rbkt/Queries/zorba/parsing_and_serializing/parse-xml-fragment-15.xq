import module namespace x = "http://www.zorba-xquery.com/modules/xml";
import schema namespace opt = "http://www.zorba-xquery.com/modules/xml-options";

x:parse-xml("<a/>", 
  <opt:options>
    <opt:parseExternalParsedEntity/>
  </opt:options>
)

