import module namespace ddl = "http://www.zorba-xquery.com/modules/ddl";
import module namespace dc = "http://www.zorba-xquery.com/modules/introspection/dctx";
import module namespace ns = "http://example.org/datamodule/" at "modifier_1.xqdata";

declare sequential function local:init() {
  (
    ddl:create-collection($ns:coll_1, (<a/>,<b/>)),
    ddl:create-collection($ns:coll_2, (<a/>,<b/>)),
    ddl:create-collection($ns:coll_3, (<a/>,<b/>,<c/>,<d/>,<e/>,<f/>,<g/>,<h/>,<i/>,<j/>,<k/>))
  );
};

declare sequential function local:testa_1() {
  try {
    block {
      ddl:delete-nodes($ns:coll_1, subsequence(ddl:collection($ns:coll_1), 1, 2));
    }
  } catch * ($error) {
    ("a",$error)
  }
};

declare sequential function local:testa_2() {
  try {
    block {
      ddl:delete-nodes($ns:coll_2, subsequence(ddl:collection($ns:coll_2), 1, 2));
    }
  } catch * ($error) {
    ("a",$error)
  }
};

declare sequential function local:testa_3() {
  try {
    block {
      ddl:delete-nodes($ns:coll_3, subsequence(ddl:collection($ns:coll_3), 2, 2));
    }
  } catch * ($error) {
    ("a",$error)
  }
};

declare sequential function local:testa_4() {
  ddl:delete-nodes($ns:coll_3, subsequence(ddl:collection($ns:coll_3), 1, 2));
};


declare sequential function local:main() {
  local:init();
  (
    local:testa_1(),
    local:testa_2(),
    local:testa_3(),
    local:testa_4(),
    <coll_1>{ddl:collection($ns:coll_1)}</coll_1>,
    <coll_2>{ddl:collection($ns:coll_2)}</coll_2>,
    <coll_3>{ddl:collection($ns:coll_3)}</coll_3>
  );
};

local:main()
