import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare %sequential function local:init() {
  init:create-collection($ns:collection_1);
  manip:insert-nodes($ns:collection_1, (<x/>,<y/>));
};

declare %sequential function local:testa() {
  try {
    block {
      manip:delete-node-first($ns:collection_1);
      manip:collection($ns:collection_1);
    }
  } catch * ($error, $desc) {
    ("a",$error, $desc)
  }
};

declare %sequential function local:testb() {
  try {
    block {
      manip:delete-node-last($ns:collection_1);
      manip:collection($ns:collection_1);
    }
  } catch * ($error, $desc) {
    ("b",$error, $desc)
  }
};

declare %sequential function local:main() {
  local:init();
  (
    local:testa(),
    local:testb()
  );
};

local:main()
