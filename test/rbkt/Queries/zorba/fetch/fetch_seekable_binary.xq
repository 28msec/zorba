import module namespace fetch = "http://www.zorba-xquery.com/modules/fetch#2.0";

import module namespace b = "http://www.zorba-xquery.com/modules/converters/base64";

(: make sure the returned string is streamable and can be consumed twice, i.e. is seekable :)
let $x := fetch:content-binary("http://www.zorba-xquery.com/modules/fetch", "MODULE")
return (b:decode($x), $x)

