import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";

import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare sequential function local:test() {
  (init:create-collection($ns:http),init:create-collection($ns:http));
};

local:test()
