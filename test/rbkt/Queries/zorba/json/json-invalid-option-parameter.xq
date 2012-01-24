(: try parsing a valid JSON string with invalid JSON option parameter :)

import module namespace json = "http://www.zorba-xquery.com/modules/converters/json";

let $options :=
  <options xmlns="http://www.zorba-xquery.com/modules/converters/json-options">
    <json-format value="array"/>
  </options>

return json:parse('{}',$options)
