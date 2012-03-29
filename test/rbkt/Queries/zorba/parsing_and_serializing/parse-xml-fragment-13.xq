import module namespace z = "http://www.zorba-xquery.com/modules/xml";
import schema namespace opt = "http://www.zorba-xquery.com/modules/xml-options";

for $var in z:parse("<from1>Jani</from1><from2>Jani</from2><from3>Jani</from3>",
  <opt:options>
    <opt:base-uri opt:value="urn:foo"/>
    <opt:parse-external-parsed-entity/>
  </opt:options>
)
return <fragment base="{fn:base-uri($var)}">{ $var }</fragment>
