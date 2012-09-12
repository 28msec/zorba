(: From bug 996084. We need to ensure that a streamable base64 item can be re-used. :)

import module namespace file = "http://expath.org/ns/file";

declare variable $filename as xs:anyURI := resolve-uri("decoded");

let $data as xs:base64Binary := file:read-binary ($filename)
let $hex as xs:hexBinary := xs:hexBinary($data)

return 
  <file>
    <base64>{$data}</base64>
    <hexBinary>{$hex}</hexBinary>
  </file>
