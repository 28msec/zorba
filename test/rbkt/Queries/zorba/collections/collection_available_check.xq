import module namespace dc = "http://www.zorba-xquery.com/module/dynamic-context";
import module namespace ddl = "http://www.zorba-xquery.com/module/ddl";

import datamodule namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare function local:testa() {
  try {
    block {
      dc:collection($ns:http);
    }
  } catch * ($error) {
    ("a",$error)
  }
};

declare function local:testb() {
  try {
    block {
      dc:index-of($ns:http, <a/>);
    }
  } catch * ($error) {
    ("b",$error)
  }
};

declare sequential function local:testc() {
  try {
    block {
      ddl:drop-collection($ns:http);
    }
  } catch * ($error) {
    ("c",$error)
  }
};

declare sequential function local:testd() {
  try {
    block {
      ddl:insert-nodes-first($ns:http, <a/>);
    }
  } catch * ($error) {
    ("d",$error)
  }
};

declare sequential function local:teste() {
  try {
    block {
      ddl:insert-nodes-last($ns:http, <a/>);
    }
  } catch * ($error) {
    ("e",$error)
  }
};

declare sequential function local:testf() {
  try {
    block {
      ddl:insert-nodes-before($ns:http, <a/>, <a/>);
    }
  } catch * ($error) {
    ("f",$error)
  }
};

declare sequential function local:testg() {
  try {
    block {
      ddl:insert-nodes-after($ns:http, <a/>, <a/>);
    }
  } catch * ($error) {
    ("g",$error)
  }
};

declare sequential function local:testh() {
  try {
    block {
      ddl:insert-nodes-at($ns:http, 1, <a/>);
    }
  } catch * ($error) {
    ("h",$error)
  }
};

declare sequential function local:testi() {
  try {
    block {
      ddl:remove-nodes($ns:http, <a/>);
    }
  } catch * ($error) {
    ("i",$error)
  }
};

declare sequential function local:testj() {
  try {
    block {
      ddl:remove-node-at($ns:http, 1);
    }
  } catch * ($error) {
    ("j",$error)
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
    local:testh(),
    local:testi(),
    local:testj()
  );
};

local:main()
