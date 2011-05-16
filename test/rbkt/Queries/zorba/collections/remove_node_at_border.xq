import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare %sequential function local:ddl() {
  ddl:create-collection($ns:collection_1);
  dml:insert-nodes($ns:collection_1, (<x/>,<y/>))
};

declare %sequential function local:testa() {
  try {
    {
      dml:delete-node-first($ns:collection_1);
      exit returning dml:collection($ns:collection_1);
    }
  } catch * ($error, $desc) {
    exit returning ("a",$error, $desc);
  }
};

declare %sequential function local:testb() {
  try {
    {
      dml:delete-node-last($ns:collection_1);
      exit returning dml:collection($ns:collection_1);
    }
  } catch * ($error, $desc) {
    exit returning ("b",$error, $desc);
  }
};

declare %sequential function local:main() {
  local:ddl();
  (
    local:testa(),
    local:testb()
  )
};

local:main()
