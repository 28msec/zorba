import module namespace fetch = "http://www.zorba-xquery.com/modules/fetch";

import module namespace b = "http://www.zorba-xquery.com/modules/converters/base64";

(: make sure the returned string is streamable and can be consumed twice, i.e. is seekable :)
let $x := fetch:content-binary(fn:resolve-uri("iso-8859-1.txt"))
return (string-length(xs:string($x)), $x)

