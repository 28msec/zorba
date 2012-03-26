import module namespace x = "http://www.zorba-xquery.com/modules/xml";
import schema namespace opt = "http://www.zorba-xquery.com/modules/xml-options";

x:parse("<?xml version='1.0'?>
<from1>Jani</from1>
<from2>Jani</from2>
<from3>Jani</from3>
", 
  <opt:options>
    <opt:parse-external-parsed-entity/>
  </opt:options>
)
