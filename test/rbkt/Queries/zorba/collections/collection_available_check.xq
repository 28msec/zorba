import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";

import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare function local:testa() {
  try {
    block {
      manip:collection($ns:http);
    }
  } catch * ($error) {
    ("a",$error)
  }
};

declare function local:testb() {
  try {
    block {
      manip:index-of($ns:http, <a/>);
    }
  } catch * ($error) {
    ("b",$error)
  }
};

declare sequential function local:testc() {
  try {
    block {
      init:delete-collection($ns:http);
    }
  } catch * ($error) {
    ("c",$error)
  }
};

declare sequential function local:testd() {
  try {
    block {
      manip:insert-nodes-first($ns:http, <a/>);
    }
  } catch * ($error) {
    ("d",$error)
  }
};

declare sequential function local:teste() {
  try {
    block {
      manip:insert-nodes-last($ns:http, <a/>);
    }
  } catch * ($error) {
    ("e",$error)
  }
};

declare sequential function local:testf() {
  try {
    block {
      manip:insert-nodes-before($ns:http, <a/>, <a/>);
    }
  } catch * ($error) {
    ("f",$error)
  }
};

declare sequential function local:testg() {
  try {
    block {
      manip:insert-nodes-after($ns:http, <a/>, <a/>);
    }
  } catch * ($error) {
    ("g",$error)
  }
};

declare sequential function local:testi() {
  try {
    block {
      manip:delete-nodes(<a/>);
    }
  } catch * ($error) {
    ("i",$error)
  }
};

declare sequential function local:main() {
  (
    local:testa(),
    local:testb(),
    local:testc(),
    local:testd(),
    local:teste(),
    local:testf(),
    local:testg(),
    local:testi()
  );
};

local:main()
