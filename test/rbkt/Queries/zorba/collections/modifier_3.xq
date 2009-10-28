import module namespace ddl = "http://www.zorba-xquery.com/module/ddl";
import module namespace dc = "http://www.zorba-xquery.com/module/dynamic-context";
import datamodule namespace ns = "http://example.org/datamodule/" at "modifier_3.xqdata";

declare sequential function local:init() {
    ddl:create-collection(xs:QName("ns:coll_1"), (<a><x/></a>,<b/>,<c/>,<d/>,<e/>,<f/>,<g/>,<h/>,<i/>,<j/>,<k/>));
};

declare function local:test1() {
  try {
    block {
      let $x as element() := dc:collection($ns:coll_1)[1]
      return
        insert node <x/> into $x;
    }
  } catch * ($error) {
    ("1",$error)
  }
};

declare function local:test2() {
  try {
    block {
      let $x as element() := dc:collection($ns:coll_1)[1]
      return
        delete node $x;
    }
  } catch * ($error) {
    ("2",$error)
  }
};

declare function local:test3() {
  try {
    block {
      let $x as element() := dc:collection($ns:coll_1)[1]
      return
        rename node $x as "blabla";
    }
  } catch * ($error) {
    ("3",$error)
  }
};

declare function local:test4() {
  try {
    block {
      let $x as element() := dc:collection($ns:coll_1)[1]
      return
        replace node $x/x with <y/>;
    }
  } catch * ($error) {
    ("4",$error)
  }
};

declare sequential function local:main() {
  local:init();
  (
    local:test1(),
    local:test2(),
    local:test3(),
    local:test4()
  );
};

local:main()
