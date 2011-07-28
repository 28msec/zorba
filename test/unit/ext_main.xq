
import module namespace refl = "http://www.zorba-xquery.com/modules/reflection";

import module namespace ext = "http://www.zorba-xquery.com/m" at "file:///${CMAKE_CURRENT_BINARY_DIR}/ext_mod.xq";

declare variable $local:foo external;

refl:eval(concat("ext:", $local:foo, "()"))
