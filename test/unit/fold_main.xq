import module namespace mod1 = "http://www.zorba-xquery.com/mod1" at "file:///${CMAKE_CURRENT_BINARY_DIR}/fold_mod1.xq";

import module namespace refl = "http://www.zorba-xquery.com/modules/reflection";

declare variable $local:foo external;

refl:eval(concat("mod1:", $local:foo, "()"))
