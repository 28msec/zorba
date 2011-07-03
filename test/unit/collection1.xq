import module namespace mod1 = "http://www.mod1.ch/" at "file:///${CMAKE_CURRENT_BINARY_DIR}/collection1.xqlib";

import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare %ann:sequential function local:test() 
{
  ddl:create-collection($mod1:coll);
  dml:insert-nodes-last($mod1:coll, (<a>one</a>,<b>two</b>));
  dml:collection($mod1:coll);
};

local:test()
