import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";
import module namespace ns = "http://example.org/datamodule/" at "modifier-01.xqdata";

declare namespace ann = "http://zorba.io/annotations";

declare namespace err = "http://www.w3.org/2005/xqt-errors";

declare %ann:sequential function local:ddl() {
  (
    ddl:create($ns:coll_1, (<a/>,<b/>)),
    ddl:create($ns:coll_2, (<a/>,<b/>)),
    ddl:create($ns:coll_3, (<a/>,<b/>,<c/>,<d/>,<e/>,<f/>,<g/>,<h/>,<i/>,<j/>,<k/>))
  );
};


declare %ann:sequential function local:testa_1() 
{
  try {
    {
      dml:delete(subsequence(dml:collection($ns:coll_1), 1, 2));
    }
  } catch *  {
    exit returning ("a",$err:code);
  }
};


declare %ann:sequential function local:testa_2() 
{
  try {
    {
      dml:delete(subsequence(dml:collection($ns:coll_2), 1, 2));
    }
  } catch * {
    exit returning ("a",$err:code);
  }
};


declare %ann:sequential function local:testa_3() 
{
  try {
    {
      dml:delete(subsequence(dml:collection($ns:coll_3), 2, 2));
    }
  } catch *  {
    exit returning ("a",$err:code);
  }
};


declare %ann:sequential function local:testa_4() 
{
  dml:delete-first($ns:coll_3, 2 cast as xs:unsignedLong);
};


declare %ann:sequential function local:main() {
  local:ddl();
  (
    local:testa_1(),
    local:testa_2(),
    local:testa_3(),
    local:testa_4(),
    <coll_1>{dml:collection($ns:coll_1)}</coll_1>,
    <coll_2>{dml:collection($ns:coll_2)}</coll_2>,
    <coll_3>{dml:collection($ns:coll_3)}</coll_3>
  )
};

local:main()
