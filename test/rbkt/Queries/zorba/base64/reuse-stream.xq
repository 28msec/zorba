(: From bug 996084. We need to ensure that a streamable base64 item can be re-used. :)

import module namespace base64="http://www.zorba-xquery.com/modules/converters/base64";
import module namespace hash = "http://www.zorba-xquery.com/modules/cryptography/hash";
import module namespace file = "http://expath.org/ns/file";

declare variable $filename as xs:anyURI := resolve-uri("decoded");

let $data as xs:base64Binary := file:read-binary ($filename)
let $md5 as xs:string := hash:md5(base64:decode($data))

return 
  <file>
    <content>{$data}</content>
    <md5>{$md5}</md5>
  </file>
