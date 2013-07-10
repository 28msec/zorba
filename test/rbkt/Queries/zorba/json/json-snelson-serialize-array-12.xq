(: valid json generation: comments should be ignored :)

import module namespace json = "http://zorba.io/modules/json-xml";

let $json :=
  <json type="array">
    <!--comment-->
    <item type="boolean">true</item>
  </json>
return json:serialize( $json )

(: vim:set et sw=2 ts=2: :)
