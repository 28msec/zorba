import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";

declare namespace ns = "http://www.unknown.com/";

declare variable $name as xs:QName := xs:QName("ns:name");

declare %sequential function local:testa() {
  try {
    {
      manip:is-available-collection($name)
    }
  } catch * ($error) {
    ("a",$error)
  }
};

declare %sequential function local:testb() {
  try {
    {
      manip:collection($name)
    }
  } catch * ($error) {
    ("b",$error)
  }
};

declare %sequential function local:testc() {
  try {
    {
      manip:index-of($name, <a/>)
    }
  } catch * ($error) {
    ("c",$error)
  }
};

declare %sequential function local:testd() {
  try {
    {
      init:create-collection($name);
    }
  } catch * ($error) {
    exit returning ("d",$error);
  }
};

declare %sequential function local:teste() {
  try {
    {
      init:delete-collection($name);
    }
  } catch * ($error) {
    exit returning ("e",$error);
  }
};

declare %sequential function local:testf() {
  try {
    {
      manip:insert-nodes-first($name, <a/>);
    }
  } catch * ($error) {
    exit returning ("f",$error);
  }
};

declare %sequential function local:testg() {
  try {
    {
      manip:insert-nodes-last($name, <a/>);
    }
  } catch * ($error) {
    exit returning ("g",$error);
  }
};

declare %sequential function local:testh() {
  try {
    {
      manip:insert-nodes-before($name, <a/>, <a/>);
    }
  } catch * ($error) {
    exit returning ("h",$error);
  }
};

declare %sequential function local:testi() {
  try {
    {
      manip:insert-nodes-after($name, <a/>, <a/>);
    }
  } catch * ($error) {
    exit returning ("i",$error);
  }
};

declare %sequential function local:testk() {
  try {
    {
      manip:delete-nodes(<a/>);
    }
  } catch * ($error) {
    exit returning ("k",$error);
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
    local:testh(),
    local:testi(),
    local:testk()
  )
};

local:main()
