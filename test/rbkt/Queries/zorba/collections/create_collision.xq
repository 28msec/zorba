import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";

import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare sequential function local:test() {
  (xqddf:create-collection($ns:http),xqddf:create-collection($ns:http));
};

local:test()
