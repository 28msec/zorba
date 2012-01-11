import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import schema namespace s = "http://www.zorba-xquery.org/schema" at "node_type.xsd";
import module namespace ns = "http://example.org/datamodule/" at "node_type.xqdata";

declare namespace ann = "http://www.zorba-xquery.com/annotations";
declare namespace err = "http://www.w3.org/2005/xqt-errors";

declare function local:create-person($name as xs:string) as schema-element(s:person) 
{
  validate { <s:person><s:name>{$name}</s:name></s:person> }
};


declare %ann:sequential function local:ddl() 
{
  ddl:create($ns:collection, local:create-person("default"));
};


declare %ann:sequential function local:testa_1() 
{
  try {
    {
      dml:insert-nodes-first($ns:collection, <a/>);
    }
  } catch * {
    exit returning ("a",$err:code);
  }
};


declare %ann:sequential function local:testa_2() 
{
  dml:insert-nodes-first($ns:collection, local:create-person("aaa"));
};


declare %ann:sequential function local:testb_1() 
{
  try {
    {
      dml:insert-nodes-last($ns:collection, <b/>);
    }
  } catch * {
    exit returning ("b",$err:code);
  }
};


declare %ann:sequential function local:testb_2() 
{
  dml:insert-nodes-last($ns:collection, local:create-person("bbb"));
};


declare %ann:sequential function local:testc_1() 
{
  try {
    {
      let $x as schema-element(s:person) := dml:collection($ns:collection)[1]
      return
        dml:insert-nodes-before($ns:collection, $x, <c/>);
    }
  } catch *  {
    exit returning ("c",$err:code);
  }
};


declare %ann:sequential function local:testc_2() 
{

  let $x as schema-element(s:person) := dml:collection($ns:collection)[2]
  return
    dml:insert-nodes-before($ns:collection, $x, local:create-person("ccc"));
};


declare %ann:sequential function local:testd_1() 
{
  try {
    {
      let $x as schema-element(s:person) := dml:collection($ns:collection)[1]
      return
        dml:insert-nodes-after($ns:collection, $x, <d/>);
    }
  } catch *  {
    exit returning ("d",$err:code);
  }
};


declare %ann:sequential function local:testd_2() 
{
  let $x as schema-element(s:person) := dml:collection($ns:collection)[3]
  return
    dml:insert-nodes-after($ns:collection, $x, local:create-person("ddd"));
};


declare %ann:sequential function local:testf_1() 
{
  try {
    {
      let $x as schema-element(s:person) := dml:collection($ns:collection)[1]
      return
        insert node <abc>4</abc> into $x;
    }
  } catch * {
    exit returning ("f",$err:code);
  }
};


declare %ann:sequential function local:testf_2() 
{
  let $x as schema-element(s:person) := dml:collection($ns:collection)[4]
  return
    insert node <s:age>4</s:age> into $x;
};


declare %ann:sequential function local:main() 
{
  local:ddl();
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
    <collection>{dml:collection($ns:collection)}</collection>
  )
};

local:main()
