import module namespace ddl = "http://www.zorba-xquery.com/modules/ddl";
import module namespace dc = "http://www.zorba-xquery.com/modules/introspection/dctx";
import datamodule namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare sequential function local:init() {
  ddl:create-collection($ns:collection_1, (<x/>,<y/>));
};

(:
declare sequential function local:testa() {
  try {
    block {
      ddl:delete-node-first($ns:collection_1);
    }
  } catch * ($error, $desc) {
    ("a",$error, $desc)
  }
};

declare sequential function local:testb() {
  try {
    block {
      ddl:delete-node-last($ns:collection_1);
    }
  } catch * ($error, $desc) {
    ("b",$error, $desc)
  }
};
:)

declare sequential function local:main() {
  local:init();
 (: (
    local:testa(),
    local:testb()
  ); :)
};

local:main()
