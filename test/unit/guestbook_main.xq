import module namespace guestbook = "http://www.28msec.com/templates/guestbook/guestbook" at "file:///@CMAKE_CURRENT_BINARY_DIR@/guestbook.xq";

import module namespace refl = "http://www.zorba-xquery.com/modules/reflection";

guestbook:init(), refl:eval("guestbook:list()")
