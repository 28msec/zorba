import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare namespace ns = "http://www.unknown.com/";
declare namespace err = "http://www.w3.org/2005/xqt-errors";

declare variable $name as xs:QName := xs:QName("ns:name");

declare %ann:sequential function local:testa() {
  try {
    {
      ddl:is-available-collection($name)
    }
  } catch * {
    ("a",$err:code)
  }
};

declare %ann:sequential function local:testb() {
  try {
    {
      dml:collection($name)
    }
  } catch * {
    ("b",$err:code)
  }
};

declare %ann:sequential function local:testc() {
  try {
    {
      dml:index-of(<a/>)
    }
  } catch *  {
    ("c",$err:code)
  }
};

declare %ann:sequential function local:testd() {
  try {
    {
      ddl:create($name);
    }
  } catch *  {
    exit returning ("d",$err:code);
  }
};

declare %ann:sequential function local:teste() {
  try {
    {
      ddl:delete($name);
    }
  } catch *  {
    exit returning ("e",$err:code);
  }
};

declare %ann:sequential function local:testf() {
  try {
    {
      dml:insert-nodes-first($name, <a/>);
    }
  } catch *  {
    exit returning ("f",$err:code);
  }
};

declare %ann:sequential function local:testg() {
  try {
    {
      dml:insert-nodes-last($name, <a/>);
    }
  } catch *  {
    exit returning ("g",$err:code);
  }
};

declare %ann:sequential function local:testh() {
  try {
    {
      dml:insert-nodes-before($name, <a/>, <a/>);
    }
  } catch *  {
    exit returning ("h",$err:code);
  }
};

declare %ann:sequential function local:testi() {
  try {
    {
      dml:insert-nodes-after($name, <a/>, <a/>);
    }
  } catch * {
    exit returning ("i",$err:code);
  }
};

declare %ann:sequential function local:testk() {
  try {
    {
      dml:delete-nodes(<a/>);
    }
  } catch *  {
    exit returning ("k",$err:code);
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
