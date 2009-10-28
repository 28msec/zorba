import module namespace ddl = "http://www.zorba-xquery.com/module/ddl";
import module namespace dc = "http://www.zorba-xquery.com/module/dynamic-context";
import datamodule namespace ns = "http://example.org/datamodule/" at "modifier_1.xqdata";

declare sequential function local:init() {
  (
    ddl:create-collection($ns:coll_1, (<a/>,<b/>)),
    ddl:create-collection($ns:coll_2, (<a/>,<b/>)),
    ddl:create-collection($ns:coll_3, (<a/>,<b/>,<c/>,<d/>,<e/>,<f/>,<g/>,<h/>,<i/>,<j/>,<k/>))
  );
};

declare function local:testa_1() {
  try {
    block {
      ddl:remove-nodes($ns:coll_1, subsequence(dc:collection($ns:coll_1), 1, 2));
    }
  } catch * ($error) {
    ("a",$error)
  }
};

declare function local:testa_2() {
  try {
    block {
      ddl:remove-nodes($ns:coll_2, subsequence(dc:collection($ns:coll_2), 1, 2));
    }
  } catch * ($error) {
    ("a",$error)
  }
};

declare function local:testa_3() {
  try {
    block {
      ddl:remove-nodes($ns:coll_3, subsequence(dc:collection($ns:coll_3), 2, 2));
    }
  } catch * ($error) {
    ("a",$error)
  }
};

declare sequential function local:testa_4() {
  ddl:remove-nodes($ns:coll_3, subsequence(dc:collection($ns:coll_3), 1, 2));
};

declare function local:testb_1() {
  try {
    block {
      ddl:remove-node-at($ns:coll_1, 1);
    }
  } catch * ($error) {
    ("b",$error)
  }
};

declare function local:testb_2() {
  try {
    block {
      ddl:remove-node-at($ns:coll_2, 1);
    }
  } catch * ($error) {
    ("b",$error)
  }
};

declare function local:testb_3() {
  try {
    block {
      ddl:remove-node-at($ns:coll_3, 2);
    }
  } catch * ($error) {
    ("b",$error)
  }
};

declare sequential function local:testb_4() {
  ddl:remove-node-at($ns:coll_3, 1);
};

declare sequential function local:main() {
  local:init();
  (
    local:testa_1(),
    local:testa_2(),
    local:testa_3(),
    local:testa_4(),
    local:testb_1(),
    local:testb_2(),
    local:testb_3(),
    local:testb_4(),
    <coll_1>{dc:collection($ns:coll_1)}</coll_1>,
    <coll_2>{dc:collection($ns:coll_2)}</coll_2>,
    <coll_3>{dc:collection($ns:coll_3)}</coll_3>
  );
};

local:main()
