import module namespace dc = "http://www.zorba-xquery.com/modules/introspection/dctx";
import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";

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
      xqddf:collection($name);
    }
  } catch * ($error) {
    ("b",$error)
  }
};

declare sequential function local:testc() {
  try {
    block {
      xqddf:index-of($name, <a/>);
    }
  } catch * ($error) {
    ("c",$error)
  }
};

declare sequential function local:testd() {
  try {
    block {
      xqddf:create-collection($name);
    }
  } catch * ($error) {
    ("d",$error)
  }
};

declare sequential function local:teste() {
  try {
    block {
      xqddf:delete-collection($name);
    }
  } catch * ($error) {
    ("e",$error)
  }
};

declare sequential function local:testf() {
  try {
    block {
      xqddf:insert-nodes-first($name, <a/>);
    }
  } catch * ($error) {
    ("f",$error)
  }
};

declare sequential function local:testg() {
  try {
    block {
      xqddf:insert-nodes-last($name, <a/>);
    }
  } catch * ($error) {
    ("g",$error)
  }
};

declare sequential function local:testh() {
  try {
    block {
      xqddf:insert-nodes-before($name, <a/>, <a/>);
    }
  } catch * ($error) {
    ("h",$error)
  }
};

declare sequential function local:testi() {
  try {
    block {
      xqddf:insert-nodes-after($name, <a/>, <a/>);
    }
  } catch * ($error) {
    ("i",$error)
  }
};

declare sequential function local:testk() {
  try {
    block {
      xqddf:delete-nodes($name, <a/>);
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
