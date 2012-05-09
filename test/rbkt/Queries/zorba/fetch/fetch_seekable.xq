import module namespace fetch = "http://www.zorba-xquery.com/modules/fetch";

import module namespace s = "http://www.zorba-xquery.com/modules/string";

(: make sure the returned string is streamable and can be consumed twice, i.e. is seekable :)
let $x := fetch:content(fn:resolve-uri("iso-8859-1.txt"))
return (s:is-streamable($x), string-length($x) gt 0, string-length($x) gt 0)

