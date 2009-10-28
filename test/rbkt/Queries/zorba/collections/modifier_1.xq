import module namespace ddl = "http://www.zorba-xquery.com/module/ddl";
import module namespace dc = "http://www.zorba-xquery.com/module/dynamic-context";
import datamodule namespace ns = "http://example.org/datamodule/" at "modifier_1.xqdata";

declare sequential function local:init() {
  (
    ddl:create-collection(xs:QName("ns:coll_1"), (<x/>,<y/>)),
    ddl:create-collection(xs:QName("ns:coll_2"), (<x/>,<y/>)),
    ddl:create-collection(xs:QName("ns:coll_3"), (<x/>,<y/>))
  );
};

declare function local:testa_1() {
  try {
    block {
      ddl:insert-nodes-first(xs:QName("ns:coll_1"), <a/>);
    }
  } catch * ($error) {
    ("a",$error)
  }
};

declare function local:testa_2() {
  try {
    block {
      ddl:insert-nodes-first(xs:QName("ns:coll_2"), <a/>);
    }
  } catch * ($error) {
    ("a",$error)
  }
};

declare function local:testa_3() {
  try {
    block {
      ddl:insert-nodes-first(xs:QName("ns:coll_3"), <a/>);
    }
  } catch * ($error) {
    ("a",$error)
  }
};

declare function local:testb_1() {
  try {
    block {
      ddl:insert-nodes-last(xs:QName("ns:coll_1"), <b/>);
    }
  } catch * ($error) {
    ("b",$error)
  }
};

declare sequential function local:testb_2() {
  ddl:insert-nodes-last(xs:QName("ns:coll_2"), <b/>);
};

declare sequential function local:testb_3() {
  ddl:insert-nodes-last(xs:QName("ns:coll_3"), <b/>);
};

declare function local:testc_1() {
  try {
    block {
      ddl:insert-nodes-before(xs:QName("ns:coll_1"), dc:collection(xs:QName("ns:coll_1")[1]), <c/>);
    }
  } catch * ($error) {
    ("c",$error)
  }
};

declare function local:testc_2() {
  try {
    block {
      ddl:insert-nodes-before(xs:QName("ns:coll_2"), dc:collection(xs:QName("ns:coll_2")[1]), <c/>);
    }
  } catch * ($error) {
    ("c",$error)
  }
};

declare function local:testc_3() {
  try {
    block {
      ddl:insert-nodes-before(xs:QName("ns:coll_3"), dc:collection(xs:QName("ns:coll_3")[1]), <c/>);
    }
  } catch * ($error) {
    ("c",$error)
  }
};

declare function local:testd_1() {
  try {
    block {
      ddl:insert-nodes-after(xs:QName("ns:coll_1"), dc:collection(xs:QName("ns:coll_1")[last()]), <d/>);
    }
  } catch * ($error) {
    ("d",$error)
  }
};

declare function local:testd_2() {
  try {
    block {
      ddl:insert-nodes-after(xs:QName("ns:coll_2"), dc:collection(xs:QName("ns:coll_2")[last()]), <d/>);
    }
  } catch * ($error) {
    ("d",$error)
  }
};

declare function local:testd_3() {
  try {
    block {
      ddl:insert-nodes-after(xs:QName("ns:coll_3"), dc:collection(xs:QName("ns:coll_3")[last()]), <d/>);
    }
  } catch * ($error) {
    ("d",$error)
  }
};

declare function local:teste_1() {
  try {
    block {
      ddl:insert-nodes-at(xs:QName("ns:coll_1"), 1, <e/>);
    }
  } catch * ($error) {
    ("e",$error)
  }
};

declare function local:teste_2() {
  try {
    block {
      ddl:insert-nodes-at(xs:QName("ns:coll_2"), 1, <e/>);
    }
  } catch * ($error) {
    ("e",$error)
  }
};

declare function local:teste_3() {
  try {
    block {
      ddl:insert-nodes-at(xs:QName("ns:coll_3"), 1, <e/>);
    }
  } catch * ($error) {
    ("e",$error)
  }
};

declare sequential function local:main() {
  local:init();
  (
    local:testa_1(),
    local:testa_2(),
    local:testa_3(),
    local:testb_1(),
    local:testb_2(),
    local:testb_3(),
    local:testc_1(),
    local:testc_2(),
    local:testc_3(),
    local:testd_1(),
    local:testd_2(),
    local:testd_3(),
    local:teste_1(),
    local:teste_2(),
    local:teste_3(),
    <coll_1>{dc:collection(xs:QName("ns:coll_1"))}</coll_1>,
    <coll_2>{dc:collection(xs:QName("ns:coll_2"))}</coll_2>,
    <coll_3>{dc:collection(xs:QName("ns:coll_3"))}</coll_3>
  );
};

local:main()
