import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";

declare namespace ns = "http://www.unknown.com/";

declare variable $name as xs:QName := xs:QName("ns:name");

declare sequential function local:testa() {
  try {
    block {
      manip:is-available-collection($name);
    }
  } catch * ($error) {
    ("a",$error)
  }
};

declare sequential function local:testb() {
  try {
    block {
      manip:collection($name);
    }
  } catch * ($error) {
    ("b",$error)
  }
};

declare sequential function local:testc() {
  try {
    block {
      manip:index-of($name, <a/>);
    }
  } catch * ($error) {
    ("c",$error)
  }
};

declare sequential function local:testd() {
  try {
    block {
      init:create-collection($name);
    }
  } catch * ($error) {
    ("d",$error)
  }
};

declare sequential function local:teste() {
  try {
    block {
      init:delete-collection($name);
    }
  } catch * ($error) {
    ("e",$error)
  }
};

declare sequential function local:testf() {
  try {
    block {
      manip:insert-nodes-first($name, <a/>);
    }
  } catch * ($error) {
    ("f",$error)
  }
};

declare sequential function local:testg() {
  try {
    block {
      manip:insert-nodes-last($name, <a/>);
    }
  } catch * ($error) {
    ("g",$error)
  }
};

declare sequential function local:testh() {
  try {
    block {
      manip:insert-nodes-before($name, <a/>, <a/>);
    }
  } catch * ($error) {
    ("h",$error)
  }
};

declare sequential function local:testi() {
  try {
    block {
      manip:insert-nodes-after($name, <a/>, <a/>);
    }
  } catch * ($error) {
    ("i",$error)
  }
};

declare sequential function local:testk() {
  try {
    block {
      manip:delete-nodes($name, <a/>);
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
