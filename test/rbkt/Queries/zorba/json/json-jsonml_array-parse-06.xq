(: try parsing an empty value :)

import module namespace json = "http://www.zorba-xquery.com/modules/converters/json";

let $options :=
  <options xmlns="http://www.zorba-xquery.com/modules/converters/json-options">
    <json-format value="JsonML-array"/>
  </options>
return json:parse( <a/>, $options )

(: vim:set et sw=2 ts=2: :)
