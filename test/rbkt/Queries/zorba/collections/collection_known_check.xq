import module namespace dc = "http://www.zorba-xquery.com/module/dynamic-context";
import module namespace ddl = "http://www.zorba-xquery.com/module/ddl";

declare namespace ns = "http://www.unknown.com/";

declare variable $name as xs:QName := xs:QName("ns:name");

declare function local:testa() {
  try {
    block {
      dc:is-available-collection($name);
    }
  } catch * ($error) {
    ("a",$error)
  }
};

declare function local:testb() {
  try {
    block {
      dc:collection($name);
    }
  } catch * ($error) {
    ("b",$error)
  }
};

declare function local:testc() {
  try {
    block {
      dc:index-of($name, <a/>);
    }
  } catch * ($error) {
    ("c",$error)
  }
};

declare function local:testd() {
  try {
    block {
      ddl:create-collection($name);
    }
  } catch * ($error) {
    ("d",$error)
  }
};

declare function local:teste() {
  try {
    block {
      ddl:drop-collection($name);
    }
  } catch * ($error) {
    ("e",$error)
  }
};

declare function local:testf() {
  try {
    block {
      ddl:insert-nodes-first($name, <a/>);
    }
  } catch * ($error) {
    ("f",$error)
  }
};

declare function local:testg() {
  try {
    block {
      ddl:insert-nodes-last($name, <a/>);
    }
  } catch * ($error) {
    ("g",$error)
  }
};

declare function local:testh() {
  try {
    block {
      ddl:insert-nodes-before($name, <a/>, <a/>);
    }
  } catch * ($error) {
    ("h",$error)
  }
};

declare function local:testi() {
  try {
    block {
      ddl:insert-nodes-after($name, <a/>, <a/>);
    }
  } catch * ($error) {
    ("i",$error)
  }
};

declare function local:testj() {
  try {
    block {
      ddl:insert-nodes-at($name, 1, <a/>);
    }
  } catch * ($error) {
    ("j",$error)
  }
};

declare function local:testk() {
  try {
    block {
      ddl:remove-nodes($name, <a/>);
    }
  } catch * ($error) {
    ("k",$error)
  }
};

declare function local:testl() {
  try {
    block {
      ddl:remove-node-at($name, 1);
    }
  } catch * ($error) {
    ("l",$error)
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
    local:testj(),
    local:testk(),
    local:testl()
  );
};

local:main()
