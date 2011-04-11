import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";
import module namespace ns = "http://example.org/datamodule/" at "modifier_1.xqdata";

declare sequential function local:init() {
  (
    init:create-collection($ns:coll_1, (<a/>,<b/>)),
    init:create-collection($ns:coll_2, (<a/>,<b/>)),
    init:create-collection($ns:coll_3, (<a/>,<b/>,<c/>,<d/>,<e/>,<f/>,<g/>,<h/>,<i/>,<j/>,<k/>))
  );
};


declare sequential function local:testa_1() 
{
  try {
    block {
      manip:delete-nodes(subsequence(manip:collection($ns:coll_1), 1, 2));
    }
  } catch * ($error) {
    ("a",$error)
  }
};


declare sequential function local:testa_2() 
{
  try {
    block {
      manip:delete-nodes(subsequence(manip:collection($ns:coll_2), 1, 2));
    }
  } catch * ($error) {
    ("a",$error)
  }
};


declare sequential function local:testa_3() 
{
  try {
    block {
      manip:delete-nodes(subsequence(manip:collection($ns:coll_3), 2, 2));
    }
  } catch * ($error) {
    ("a",$error)
  }
};


declare sequential function local:testa_4() 
{
  manip:delete-nodes-first($ns:coll_3, 2 cast as xs:unsignedLong);
};


declare sequential function local:main() {
  local:init();
  (
    local:testa_1(),
    local:testa_2(),
    local:testa_3(),
    local:testa_4(),
    <coll_1>{manip:collection($ns:coll_1)}</coll_1>,
    <coll_2>{manip:collection($ns:coll_2)}</coll_2>,
    <coll_3>{manip:collection($ns:coll_3)}</coll_3>
  );
};

local:main()
