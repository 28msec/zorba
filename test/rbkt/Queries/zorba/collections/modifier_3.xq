import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace ns = "http://example.org/datamodule/" at "modifier_3.xqdata";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare %ann:sequential function local:ddl() {
    ddl:create-collection(xs:QName("ns:coll_1"), (<a><x/></a>,<b/>,<c/>,<d/>,<e/>,<f/>,<g/>,<h/>,<i/>,<j/>,<k/>));
};

declare %ann:sequential function local:test1() {
  try {
    {
      let $x as element() := dml:collection($ns:coll_1)[1]
      return
        insert node <x/> into $x;
    }
  } catch * ($error) {
    exit returning ("1",$error);
  }
};

declare %ann:sequential function local:test2() {
  try {
    {
      let $x as element() := dml:collection($ns:coll_1)[1]
      return
        delete node $x;
    }
  } catch * ($error) {
    exit returning ("2",$error);
  }
};

declare %ann:sequential function local:test3() {
  try {
    {
      let $x as element() := dml:collection($ns:coll_1)[1]
      return
        rename node $x as "blabla";
    }
  } catch * ($error) {
    exit returning ("3",$error);
  }
};

declare %ann:sequential function local:test4() {
  try {
    {
      let $x as element() := dml:collection($ns:coll_1)[1]
      return
        replace node $x/x with <y/>;
    }
  } catch * ($error) {
    exit returning ("4",$error);
  }
};

declare %ann:sequential function local:main() {
  local:ddl();
  (
    local:test1(),
    local:test2(),
    local:test3(),
    local:test4()
  )
};

local:main()
