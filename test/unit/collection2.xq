
import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";

import module namespace mod2 = "http://www.mod2.ch/" at "file:///${CMAKE_CURRENT_BINARY_DIR}/collection2.xqlib";

declare namespace mod1 = "http://www.mod1.ch/";

declare %sequential function local:test() 
{
  xqddf:insert-nodes-first(xs:QName("mod1:coll"), (<a>three</a>,<b>four</b>));
  xqddf:collection(xs:QName("mod1:coll"));
};

local:test()
