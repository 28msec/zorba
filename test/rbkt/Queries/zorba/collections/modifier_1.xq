import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace ns = "http://example.org/datamodule/" at "modifier_1.xqdata";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare %ann:sequential function local:ddl() {
  (
    ddl:create-collection($ns:coll_1, (<x/>,<y/>)),
    ddl:create-collection($ns:coll_2, (<x/>,<y/>)),
    ddl:create-collection($ns:coll_3, (<x/>,<y/>))
  );
};


declare %ann:sequential function local:testa_1() {
  try {
    {
      dml:insert-nodes-first($ns:coll_1, <a/>);
    }
  } catch * ($error) {
    exit returning ("a",$error);
  }
};


declare %ann:sequential function local:testa_2() {
  try {
    {
      dml:insert-nodes-first($ns:coll_2, <a/>);
    }
  } catch * ($error) {
    exit returning ("a",$error);
  }
};

declare %ann:sequential function local:testa_3() {
  try {
    {
      dml:insert-nodes-first($ns:coll_3, <a/>);
    }
  } catch * ($error) {
    exit returning ("a",$error);
  }
};

declare %ann:sequential function local:testb_1() {
  try {
    {
      dml:insert-nodes-last($ns:coll_1, <b/>);
    }
  } catch * ($error) {
    exit returning ("b",$error);
  }
};


declare %ann:sequential function local:testb_2() {
  dml:insert-nodes-last($ns:coll_2, <b/>);
};


declare %ann:sequential function local:testb_3() {
  dml:insert-nodes-last($ns:coll_3, <b/>);
};


declare %ann:sequential function local:testc_1() {
  try {
    {
      dml:insert-nodes-before($ns:coll_1, dml:collection($ns:coll_1)[1], <c/>);
    }
  } catch * ($error) {
    exit returning ("c",$error);
  }
};


declare %ann:sequential function local:testc_2() {
  try {
    {
      dml:insert-nodes-before($ns:coll_2, dml:collection($ns:coll_2)[1], <c/>);
    }
  } catch * ($error) {
    exit returning ("c",$error);
  }
};


declare %ann:sequential function local:testc_3() {
  try {
    {
      dml:insert-nodes-before($ns:coll_3, dml:collection($ns:coll_3)[1], <c/>);
    }
  } catch * ($error) {
    exit returning ("c",$error);
  }
};


declare %ann:sequential function local:testd_1() {
  try {
    {
      dml:insert-nodes-after($ns:coll_1, dml:collection($ns:coll_1)[last()], <d/>);
    }
  } catch * ($error) {
    exit returning ("d",$error);
  }
};


declare %ann:sequential function local:testd_2() {
  try {
    {
      dml:insert-nodes-after($ns:coll_2, dml:collection($ns:coll_2)[last()], <d/>);
    }
  } catch * ($error) {
    exit returning ("d",$error);
  }
};


declare %ann:sequential function local:testd_3() {
  try {
    {
      dml:insert-nodes-after($ns:coll_3, dml:collection($ns:coll_3)[last()], <d/>);
    }
  } catch * ($error) {
    exit returning ("d",$error);
  }
};


declare %ann:sequential function local:main() {
  local:ddl();
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
    <coll_1>{dml:collection($ns:coll_1)}</coll_1>,
    <coll_2>{dml:collection($ns:coll_2)}</coll_2>,
    <coll_3>{dml:collection($ns:coll_3)}</coll_3>
  )
};

local:main()
