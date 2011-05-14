import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";
import module namespace ns = "http://example.org/datamodule/" at "modifier_1.xqdata";

declare %sequential function local:init() {
  (
    init:create-collection($ns:coll_1, (<x/>,<y/>)),
    init:create-collection($ns:coll_2, (<x/>,<y/>)),
    init:create-collection($ns:coll_3, (<x/>,<y/>))
  );
};


declare %sequential function local:testa_1() {
  try {
    {
      manip:insert-nodes-first($ns:coll_1, <a/>);
    }
  } catch * ($error) {
    exit returning ("a",$error);
  }
};


declare %sequential function local:testa_2() {
  try {
    {
      manip:insert-nodes-first($ns:coll_2, <a/>);
    }
  } catch * ($error) {
    exit returning ("a",$error);
  }
};

declare %sequential function local:testa_3() {
  try {
    {
      manip:insert-nodes-first($ns:coll_3, <a/>);
    }
  } catch * ($error) {
    exit returning ("a",$error);
  }
};

declare %sequential function local:testb_1() {
  try {
    {
      manip:insert-nodes-last($ns:coll_1, <b/>);
    }
  } catch * ($error) {
    exit returning ("b",$error);
  }
};


declare %sequential function local:testb_2() {
  manip:insert-nodes-last($ns:coll_2, <b/>);
};


declare %sequential function local:testb_3() {
  manip:insert-nodes-last($ns:coll_3, <b/>);
};


declare %sequential function local:testc_1() {
  try {
    {
      manip:insert-nodes-before($ns:coll_1, manip:collection($ns:coll_1)[1], <c/>);
    }
  } catch * ($error) {
    exit returning ("c",$error);
  }
};


declare %sequential function local:testc_2() {
  try {
    {
      manip:insert-nodes-before($ns:coll_2, manip:collection($ns:coll_2)[1], <c/>);
    }
  } catch * ($error) {
    exit returning ("c",$error);
  }
};


declare %sequential function local:testc_3() {
  try {
    {
      manip:insert-nodes-before($ns:coll_3, manip:collection($ns:coll_3)[1], <c/>);
    }
  } catch * ($error) {
    exit returning ("c",$error);
  }
};


declare %sequential function local:testd_1() {
  try {
    {
      manip:insert-nodes-after($ns:coll_1, manip:collection($ns:coll_1)[last()], <d/>);
    }
  } catch * ($error) {
    exit returning ("d",$error);
  }
};


declare %sequential function local:testd_2() {
  try {
    {
      manip:insert-nodes-after($ns:coll_2, manip:collection($ns:coll_2)[last()], <d/>);
    }
  } catch * ($error) {
    exit returning ("d",$error);
  }
};


declare %sequential function local:testd_3() {
  try {
    {
      manip:insert-nodes-after($ns:coll_3, manip:collection($ns:coll_3)[last()], <d/>);
    }
  } catch * ($error) {
    exit returning ("d",$error);
  }
};


declare %sequential function local:main() {
  local:init();
  (
    local:testa_1(),
    local:testa_2(),
    local:testa_3(),
    local:testb_1(),
    local:testb_2(),
    local:testb_3(),
    local:testc_1(),
    local:testc_2(),
    local:testc_3(),
    local:testd_1(),
    local:testd_2(),
    local:testd_3(),
    <coll_1>{manip:collection($ns:coll_1)}</coll_1>,
    <coll_2>{manip:collection($ns:coll_2)}</coll_2>,
    <coll_3>{manip:collection($ns:coll_3)}</coll_3>
  )
};

local:main()
