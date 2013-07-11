(: valid json generation: comments should be ignored :)

import module namespace jx = "http://zorba.io/modules/json-xml";

let $json :=
  <json type="object">
    <!--comment-->
    <pair name="a" type="number">1</pair>
    <!--comment-->
  </json>
return jx:xml-to-json( $json )

(: vim:set et sw=2 ts=2: :)
