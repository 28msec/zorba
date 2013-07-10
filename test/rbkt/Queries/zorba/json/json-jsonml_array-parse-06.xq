(: try parsing an empty value :)

import module namespace json = "http://zorba.io/modules/json-xml";

let $options :=
  <options xmlns="http://zorba.io/modules/json-xml-options">
    <json-format value="JsonML-array"/>
  </options>
return json:parse( <a/>, $options )

(: vim:set et sw=2 ts=2: :)
