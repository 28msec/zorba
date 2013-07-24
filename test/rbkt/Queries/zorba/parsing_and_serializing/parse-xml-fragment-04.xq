import module namespace x = "http://zorba.io/modules/xml";
import schema namespace opt = "http://zorba.io/modules/xml-options";

x:parse("
<from1>Jani</from1>
<from2>Jani</from2>
<from3>Jani</from3>
", 
  <opt:options>
    <opt:parse-external-parsed-entity/>
  </opt:options>
)
