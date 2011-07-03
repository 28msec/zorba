import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare namespace ns = "http://www.unknown.com/";

declare variable $name as xs:QName := xs:QName("ns:name");

declare %ann:sequential function local:testa() {
  try {
    {
      ddl:is-available-collection($name)
    }
  } catch * ($error) {
    ("a",$error)
  }
};

declare %ann:sequential function local:testb() {
  try {
    {
      dml:collection($name)
    }
  } catch * ($error) {
    ("b",$error)
  }
};

declare %ann:sequential function local:testc() {
  try {
    {
      dml:index-of(<a/>)
    }
  } catch * ($error) {
    ("c",$error)
  }
};

declare %ann:sequential function local:testd() {
  try {
    {
      ddl:create-collection($name);
    }
  } catch * ($error) {
    exit returning ("d",$error);
  }
};

declare %ann:sequential function local:teste() {
  try {
    {
      ddl:delete-collection($name);
    }
  } catch * ($error) {
    exit returning ("e",$error);
  }
};

declare %ann:sequential function local:testf() {
  try {
    {
      dml:insert-nodes-first($name, <a/>);
    }
  } catch * ($error) {
    exit returning ("f",$error);
  }
};

declare %ann:sequential function local:testg() {
  try {
    {
      dml:insert-nodes-last($name, <a/>);
    }
  } catch * ($error) {
    exit returning ("g",$error);
  }
};

declare %ann:sequential function local:testh() {
  try {
    {
      dml:insert-nodes-before($name, <a/>, <a/>);
    }
  } catch * ($error) {
    exit returning ("h",$error);
  }
};

declare %ann:sequential function local:testi() {
  try {
    {
      dml:insert-nodes-after($name, <a/>, <a/>);
    }
  } catch * ($error) {
    exit returning ("i",$error);
  }
};

declare %ann:sequential function local:testk() {
  try {
    {
      dml:delete-nodes(<a/>);
    }
  } catch * ($error) {
    exit returning ("k",$error);
  }
};

declare %ann:sequential function local:main() {
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
