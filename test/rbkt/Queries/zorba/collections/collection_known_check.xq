import module namespace dc = "http://www.zorba-xquery.com/modules/introspection/dctx";
import module namespace ddl = "http://www.zorba-xquery.com/modules/ddl";

declare namespace ns = "http://www.unknown.com/";

declare variable $name as xs:QName := xs:QName("ns:name");

declare sequential function local:testa() {
  try {
    block {
      dc:is-available-collection($name);
    }
  } catch * ($error) {
    ("a",$error)
  }
};

declare sequential function local:testb() {
  try {
    block {
      ddl:collection($name);
    }
  } catch * ($error) {
    ("b",$error)
  }
};

declare sequential function local:testc() {
  try {
    block {
      ddl:index-of($name, <a/>);
    }
  } catch * ($error) {
    ("c",$error)
  }
};

declare sequential function local:testd() {
  try {
    block {
      ddl:create-collection($name);
    }
  } catch * ($error) {
    ("d",$error)
  }
};

declare sequential function local:teste() {
  try {
    block {
      ddl:delete-collection($name);
    }
  } catch * ($error) {
    ("e",$error)
  }
};

declare sequential function local:testf() {
  try {
    block {
      ddl:insert-nodes-first($name, <a/>);
    }
  } catch * ($error) {
    ("f",$error)
  }
};

declare sequential function local:testg() {
  try {
    block {
      ddl:insert-nodes-last($name, <a/>);
    }
  } catch * ($error) {
    ("g",$error)
  }
};

declare sequential function local:testh() {
  try {
    block {
      ddl:insert-nodes-before($name, <a/>, <a/>);
    }
  } catch * ($error) {
    ("h",$error)
  }
};

declare sequential function local:testi() {
  try {
    block {
      ddl:insert-nodes-after($name, <a/>, <a/>);
    }
  } catch * ($error) {
    ("i",$error)
  }
};

declare sequential function local:testk() {
  try {
    block {
      ddl:delete-nodes($name, <a/>);
    }
  } catch * ($error) {
    ("k",$error)
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
    local:testk()
  );
};

local:main()
