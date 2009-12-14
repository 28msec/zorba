import module namespace dc = "http://www.zorba-xquery.com/modules/introspection/dctx";
import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";

import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare function local:testa() {
  try {
    block {
      xqddf:collection($ns:http);
    }
  } catch * ($error) {
    ("a",$error)
  }
};

declare function local:testb() {
  try {
    block {
      xqddf:index-of($ns:http, <a/>);
    }
  } catch * ($error) {
    ("b",$error)
  }
};

declare sequential function local:testc() {
  try {
    block {
      xqddf:delete-collection($ns:http);
    }
  } catch * ($error) {
    ("c",$error)
  }
};

declare sequential function local:testd() {
  try {
    block {
      xqddf:insert-nodes-first($ns:http, <a/>);
    }
  } catch * ($error) {
    ("d",$error)
  }
};

declare sequential function local:teste() {
  try {
    block {
      xqddf:insert-nodes-last($ns:http, <a/>);
    }
  } catch * ($error) {
    ("e",$error)
  }
};

declare sequential function local:testf() {
  try {
    block {
      xqddf:insert-nodes-before($ns:http, <a/>, <a/>);
    }
  } catch * ($error) {
    ("f",$error)
  }
};

declare sequential function local:testg() {
  try {
    block {
      xqddf:insert-nodes-after($ns:http, <a/>, <a/>);
    }
  } catch * ($error) {
    ("g",$error)
  }
};

declare sequential function local:testi() {
  try {
    block {
      xqddf:delete-nodes($ns:http, <a/>);
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
