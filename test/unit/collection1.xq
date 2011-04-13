import module namespace mod1 = "http://www.mod1.ch/" at "file:///${CMAKE_CURRENT_BINARY_DIR}/collection1.xqlib";

import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";

declare %sequential function local:test() 
{
  xqddf:create-collection($mod1:coll);
  xqddf:insert-nodes-last($mod1:coll, (<a>one</a>,<b>two</b>));
  xqddf:collection($mod1:coll);
};

local:test()
