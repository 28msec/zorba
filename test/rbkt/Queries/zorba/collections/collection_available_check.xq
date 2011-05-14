import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";

import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare function local:testa() {
  try {
    {
      manip:collection($ns:http)
    }
  } catch * ($error) {
    ("a",$error)
  }
};

declare function local:testb() {
  try {
    {
      manip:index-of($ns:http, <a/>)
    }
  } catch * ($error) {
    ("b",$error)
  }
};

declare %sequential function local:testc() {
  try {
    {
      init:delete-collection($ns:http);
    }
  } catch * ($error) {
    exit returning ("c",$error);
  }
};

declare %sequential function local:testd() {
  try {
    {
      manip:insert-nodes-first($ns:http, <a/>);
    }
  } catch * ($error) {
    exit returning ("d",$error);
  }
};

declare %sequential function local:teste() {
  try {
    {
      manip:insert-nodes-last($ns:http, <a/>);
    }
  } catch * ($error) {
    exit returning ("e",$error);
  }
};

declare %sequential function local:testf() {
  try {
    {
      manip:insert-nodes-before($ns:http, <a/>, <a/>);
    }
  } catch * ($error) {
    exit returning ("f",$error);
  }
};

declare %sequential function local:testg() {
  try {
    {
      manip:insert-nodes-after($ns:http, <a/>, <a/>);
    }
  } catch * ($error) {
    exit returning ("g",$error);
  }
};

declare %sequential function local:testi() {
  try {
    {
      manip:delete-nodes(<a/>);
    }
  } catch * ($error) {
    exit returning ("i",$error);
  }
};

declare %sequential function local:main() {
  (
    local:testa(),
    local:testb(),
    local:testc(),
    local:testd(),
    local:teste(),
    local:testf(),
    local:testg(),
    local:testi()
  )
};

local:main()
