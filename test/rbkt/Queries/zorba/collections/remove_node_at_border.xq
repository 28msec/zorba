import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";
import module namespace dc = "http://www.zorba-xquery.com/modules/introspection/dctx";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare sequential function local:init() {
  xqddf:create-collection($ns:collection_1);
  xqddf:insert-nodes($ns:collection_1, (<x/>,<y/>));
};

declare sequential function local:testa() {
  try {
    block {
      xqddf:delete-node-first($ns:collection_1);
      xqddf:collection($ns:collection_1);
    }
  } catch * ($error, $desc) {
    ("a",$error, $desc)
  }
};

declare sequential function local:testb() {
  try {
    block {
      xqddf:delete-node-last($ns:collection_1);
      xqddf:collection($ns:collection_1);
    }
  } catch * ($error, $desc) {
    ("b",$error, $desc)
  }
};

declare sequential function local:main() {
  local:init();
  (
    local:testa(),
    local:testb()
  );
};

local:main()
