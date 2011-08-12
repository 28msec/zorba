import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";

import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare namespace ann = "http://www.zorba-xquery.com/annotations";
declare namespace err = "http://www.w3.org/2005/xqt-errors";

declare function local:testa() {
  try {
    {
      dml:collection($ns:http)
    }
  } catch *  {
    ("a",$err:code)
  }
};

declare function local:testb() {
  try {
    {
      dml:index-of(<a/>)
    }
  } catch *  {
    ("b",$err:code)
  }
};

declare %ann:sequential function local:testc() {
  try {
    {
      ddl:delete($ns:http);
    }
  } catch *  {
    exit returning ("c",$err:code);
  }
};

declare %ann:sequential function local:testd() {
  try {
    {
      dml:insert-nodes-first($ns:http, <a/>);
    }
  } catch *  {
    exit returning ("d",$err:code);
  }
};

declare %ann:sequential function local:teste() {
  try {
    {
      dml:insert-nodes-last($ns:http, <a/>);
    }
  } catch *  {
    exit returning ("e",$err:code);
  }
};

declare %ann:sequential function local:testf() {
  try {
    {
      dml:insert-nodes-before($ns:http, <a/>, <a/>);
    }
  } catch *  {
    exit returning ("f",$err:code);
  }
};

declare %ann:sequential function local:testg() {
  try {
    {
      dml:insert-nodes-after($ns:http, <a/>, <a/>);
    }
  } catch *  {
    exit returning ("g",$err:code);
  }
};

declare %ann:sequential function local:testi() {
  try {
    {
      dml:delete-nodes(<a/>);
    }
  } catch *  {
    exit returning ("i",$err:code);
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
