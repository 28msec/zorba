import module namespace z = "http://zorba.io/modules/xml";
import schema namespace opt = "http://zorba.io/modules/xml-options";

let $var := z:parse("<?xml version='1.0'?>
<from1>Jani</from1>
<from2>Jani</from2>
<from3>Jani</from3>", 
  <opt:options>
    <opt:parse-external-parsed-entity/>
  </opt:options>
)
return <fragment>{ $var }<count>{ count($var) }</count></fragment>