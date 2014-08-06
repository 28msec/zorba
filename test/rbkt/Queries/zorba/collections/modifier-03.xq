import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";
import module namespace ns = "http://example.org/datamodule/" at "modifier-03.xqdata";

declare namespace ann = "http://zorba.io/annotations";
declare namespace err = "http://www.w3.org/2005/xqt-errors";

declare %ann:sequential function local:ddl() {
    ddl:create(xs:QName("ns:coll_1"), (<a><x/></a>,<b/>,<c/>,<d/>,<e/>,<f/>,<g/>,<h/>,<i/>,<j/>,<k/>));
};

declare %ann:sequential function local:test1() {
  try {
    {
      let $x as element() := dml:collection($ns:coll_1)[1]
      return
        insert node <x/> into $x;
    }
  } catch *  {
    exit returning ("1",$err:code);
  }
};

declare %ann:sequential function local:test2() {
  try {
    {
      let $x as element() := dml:collection($ns:coll_1)[1]
      return
        delete node $x;
    }
  } catch *  {
    exit returning ("2",$err:code);
  }
};

declare %ann:sequential function local:test3() {
  try {
    {
      let $x as element() := dml:collection($ns:coll_1)[1]
      return
        rename node $x as "blabla";
    }
  } catch *  {
    exit returning ("3",$err:code);
  }
};

declare %ann:sequential function local:test4() {
  try {
    {
      let $x as element() := dml:collection($ns:coll_1)[name() eq "a"]
      return
        replace node $x/x with <y/>;
    }
  } catch *  {
    exit returning ("4",$err:code);
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
