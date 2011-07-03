import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";

import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare function local:testa() {
  try {
    {
      dml:collection($ns:http)
    }
  } catch * ($error) {
    ("a",$error)
  }
};

declare function local:testb() {
  try {
    {
      dml:index-of(<a/>)
    }
  } catch * ($error) {
    ("b",$error)
  }
};

declare %ann:sequential function local:testc() {
  try {
    {
      ddl:delete-collection($ns:http);
    }
  } catch * ($error) {
    exit returning ("c",$error);
  }
};

declare %ann:sequential function local:testd() {
  try {
    {
      dml:insert-nodes-first($ns:http, <a/>);
    }
  } catch * ($error) {
    exit returning ("d",$error);
  }
};

declare %ann:sequential function local:teste() {
  try {
    {
      dml:insert-nodes-last($ns:http, <a/>);
    }
  } catch * ($error) {
    exit returning ("e",$error);
  }
};

declare %ann:sequential function local:testf() {
  try {
    {
      dml:insert-nodes-before($ns:http, <a/>, <a/>);
    }
  } catch * ($error) {
    exit returning ("f",$error);
  }
};

declare %ann:sequential function local:testg() {
  try {
    {
      dml:insert-nodes-after($ns:http, <a/>, <a/>);
    }
  } catch * ($error) {
    exit returning ("g",$error);
  }
};

declare %ann:sequential function local:testi() {
  try {
    {
      dml:delete-nodes(<a/>);
    }
  } catch * ($error) {
    exit returning ("i",$error);
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
    local:testi()
  )
};

local:main()
