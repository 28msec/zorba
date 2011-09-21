import module namespace lib = "a:b" at "schema1-lib1.xqlib";

import schema namespace f = "http://expath.org/ns/http-client";


lib:test(validate { <f:request href="http://www.test.com" method="GET"/> }), '
'

