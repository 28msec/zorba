import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";

import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare namespace ann = "http://zorba.io/annotations";

declare %ann:sequential function local:test() {
  (ddl:create($ns:http),ddl:create($ns:http));
};

local:test()
