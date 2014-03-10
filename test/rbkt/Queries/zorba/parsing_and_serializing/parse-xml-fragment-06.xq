import module namespace x = "http://zorba.io/modules/xml";
import schema namespace opt = "http://zorba.io/modules/xml-options";

x:parse("<?xml version='1.0'?>
<from1>Jani</from1>
<from2>Jani</from2>
<from3>Jani</from3>
", 
  <opt:options>
    <opt:DTD-validate/>
  </opt:options>
)
