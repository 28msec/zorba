import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";
import module namespace dc = "http://www.zorba-xquery.com/modules/introspection/dctx";
import schema namespace s = "http://www.zorba-xquery.org/schema" at "node_type.xsd";
import module namespace ns = "http://example.org/datamodule/" at "node_type.xqdata";


declare function local:create-person($name as xs:string) as schema-element(s:person) 
{
  validate { <s:person><s:name>{$name}</s:name></s:person> }
};


declare sequential function local:init() 
{
  xqddf:create-collection($ns:collection, local:create-person("default"));
};


declare sequential function local:testa_1() 
{
  try {
    block {
      xqddf:insert-nodes-first($ns:collection, <a/>);
    }
  } catch * ($error) {
    ("a",$error)
  }
};


declare sequential function local:testa_2() 
{
  xqddf:insert-nodes-first($ns:collection, local:create-person("aaa"));
};


declare sequential function local:testb_1() 
{
  try {
    block {
      xqddf:insert-nodes-last($ns:collection, <b/>);
    }
  } catch * ($error) {
    ("b",$error)
  }
};


declare sequential function local:testb_2() 
{
  xqddf:insert-nodes-last($ns:collection, local:create-person("bbb"));
};


declare sequential function local:testc_1() 
{
  try {
    block {
      let $x as schema-element(s:person) := xqddf:collection($ns:collection)[1]
      return
        xqddf:insert-nodes-before($ns:collection, $x, <c/>);
    }
  } catch * ($error) {
    ("c",$error)
  }
};


declare sequential function local:testc_2() 
{

  let $x as schema-element(s:person) := xqddf:collection($ns:collection)[2]
  return
    xqddf:insert-nodes-before($ns:collection, $x, local:create-person("ccc"));
};


declare sequential function local:testd_1() 
{
  try {
    block {
      let $x as schema-element(s:person) := xqddf:collection($ns:collection)[1]
      return
        xqddf:insert-nodes-after($ns:collection, $x, <d/>);
    }
  } catch * ($error) {
    ("d",$error)
  }
};


declare sequential function local:testd_2() 
{
  let $x as schema-element(s:person) := xqddf:collection($ns:collection)[3]
  return
    xqddf:insert-nodes-after($ns:collection, $x, local:create-person("ddd"));
};


declare sequential function local:testf_1() 
{
  try {
    block {
      let $x as schema-element(s:person) := xqddf:collection($ns:collection)[1]
      return
        insert node <abc>4</abc> into $x;
    }
  } catch * ($error) {
    ("f",$error)
  }
};


declare sequential function local:testf_2() 
{
  let $x as schema-element(s:person) := xqddf:collection($ns:collection)[4]
  return
    insert node <s:age>4</s:age> into $x;
};


declare sequential function local:main() 
{
  local:init();
  (
    local:testa_1(),
    local:testa_2(),
    local:testb_1(),
    local:testb_2(),
    local:testc_1(),
    local:testc_2(),
    local:testd_1(),
    local:testd_2(),
    local:testf_1(),
    local:testf_2(),
    <collection>{xqddf:collection($ns:collection)}</collection>
  );
};

local:main()
