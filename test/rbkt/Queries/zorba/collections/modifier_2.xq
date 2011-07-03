import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace ns = "http://example.org/datamodule/" at "modifier_1.xqdata";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare %ann:sequential function local:ddl() {
  (
    ddl:create-collection($ns:coll_1, (<a/>,<b/>)),
    ddl:create-collection($ns:coll_2, (<a/>,<b/>)),
    ddl:create-collection($ns:coll_3, (<a/>,<b/>,<c/>,<d/>,<e/>,<f/>,<g/>,<h/>,<i/>,<j/>,<k/>))
  );
};


declare %ann:sequential function local:testa_1() 
{
  try {
    {
      dml:delete-nodes(subsequence(dml:collection($ns:coll_1), 1, 2));
    }
  } catch * ($error) {
    exit returning ("a",$error);
  }
};


declare %ann:sequential function local:testa_2() 
{
  try {
    {
      dml:delete-nodes(subsequence(dml:collection($ns:coll_2), 1, 2));
    }
  } catch * ($error) {
    exit returning ("a",$error);
  }
};


declare %ann:sequential function local:testa_3() 
{
  try {
    {
      dml:delete-nodes(subsequence(dml:collection($ns:coll_3), 2, 2));
    }
  } catch * ($error) {
    exit returning ("a",$error);
  }
};


declare %ann:sequential function local:testa_4() 
{
  dml:delete-nodes-first($ns:coll_3, 2 cast as xs:unsignedLong);
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
