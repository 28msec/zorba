import module namespace fetch = "http://zorba.io/modules/fetch";

import module namespace b = "http://zorba.io/modules/base64";

(: make sure the returned string is streamable and can be consumed twice, i.e. is seekable :)
let $x := fetch:content-binary(fn:resolve-uri("iso-8859-1.txt"))
return (string-length(xs:string($x)), $x)

