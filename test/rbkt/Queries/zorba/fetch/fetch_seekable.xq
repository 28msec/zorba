import module namespace fetch = "http://zorba.io/modules/fetch";

import module namespace s = "http://zorba.io/modules/string";

(: make sure the returned string is streamable and can be consumed twice, i.e. is seekable :)
let $x := fetch:content(fn:resolve-uri("iso-8859-1.txt"))
return (s:is-streamable($x), string-length($x) gt 0, string-length($x) gt 0)

