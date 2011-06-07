module namespace mod2 = "http://www.mod2.com/";

import module namespace mod3 = "http://www.mod3.com/" at "file:///${CMAKE_CURRENT_BINARY_DIR}/module3.xq";

declare ordered collection mod2:coll as node()*;
