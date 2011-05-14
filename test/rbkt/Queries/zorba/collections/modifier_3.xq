import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";
import module namespace ns = "http://example.org/datamodule/" at "modifier_3.xqdata";

declare %sequential function local:init() {
    init:create-collection(xs:QName("ns:coll_1"), (<a><x/></a>,<b/>,<c/>,<d/>,<e/>,<f/>,<g/>,<h/>,<i/>,<j/>,<k/>));
};

declare %sequential function local:test1() {
  try {
    {
      let $x as element() := manip:collection($ns:coll_1)[1]
      return
        insert node <x/> into $x;
    }
  } catch * ($error) {
    exit returning ("1",$error);
  }
};

declare %sequential function local:test2() {
  try {
    {
      let $x as element() := manip:collection($ns:coll_1)[1]
      return
        delete node $x;
    }
  } catch * ($error) {
    exit returning ("2",$error);
  }
};

declare %sequential function local:test3() {
  try {
    {
      let $x as element() := manip:collection($ns:coll_1)[1]
      return
        rename node $x as "blabla";
    }
  } catch * ($error) {
    exit returning ("3",$error);
  }
};

declare %sequential function local:test4() {
  try {
    {
      let $x as element() := manip:collection($ns:coll_1)[1]
      return
        replace node $x/x with <y/>;
    }
  } catch * ($error) {
    exit returning ("4",$error);
  }
};

declare %sequential function local:main() {
  local:init();
  (
    local:test1(),
    local:test2(),
    local:test3(),
    local:test4()
  )
};

local:main()
