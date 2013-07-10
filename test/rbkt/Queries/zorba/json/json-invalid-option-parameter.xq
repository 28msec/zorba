(: try parsing a valid JSON string with invalid JSON option parameter :)

import module namespace json = "http://zorba.io/modules/json-xml";

let $options :=
  <options xmlns="http://zorba.io/modules/json-xml-options">
    <json-format value="array"/>
  </options>

return json:parse('{}',$options)
