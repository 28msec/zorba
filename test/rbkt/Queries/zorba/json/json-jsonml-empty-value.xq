(: try parsing an empty value :)

import module namespace json = "http://www.zorba-xquery.com/modules/converters/json";

let $options :=
  <options xmlns="http://www.zorba-xquery.com/modules/converters/json-options">
    <json-format value="JsonML-array"/>
  </options>

json:parse(<a/>,$options)
