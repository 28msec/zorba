import module namespace jx = "http://zorba.io/modules/json-xml";

let $xml := <message type="array">Hello, world!</message>
return jx:xml-to-json( $xml )

(: vim:set et sw=2 ts=2: :)
