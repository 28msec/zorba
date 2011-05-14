import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare %sequential function local:init() {
  init:create-collection($ns:collection_1);
  manip:insert-nodes($ns:collection_1, (<x/>,<y/>))
};

declare %sequential function local:testa() {
  try {
    {
      manip:delete-node-first($ns:collection_1);
      exit returning manip:collection($ns:collection_1);
    }
  } catch * ($error, $desc) {
    exit returning ("a",$error, $desc);
  }
};

declare %sequential function local:testb() {
  try {
    {
      manip:delete-node-last($ns:collection_1);
      exit returning manip:collection($ns:collection_1);
    }
  } catch * ($error, $desc) {
    exit returning ("b",$error, $desc);
  }
};

declare %sequential function local:main() {
  local:init();
  (
    local:testa(),
    local:testb()
  )
};

local:main()
