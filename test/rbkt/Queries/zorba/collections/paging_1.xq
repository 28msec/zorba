import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";
import module namespace ref = "http://www.zorba-xquery.com/modules/node-reference";

declare namespace ann = "http://www.zorba-xquery.com/annotations";
declare namespace zerr = "http://zorba.io/modules/zorba-errors";

declare function local:order($items)
{
  for $item in $items
  order by fn:local-name($item)
  return $item
};

declare %ann:sequential function local:test()
{
  ddl:create(xs:QName("ns:test2"));
  dml:insert-nodes(xs:QName("ns:test2"), <a/>);
  dml:insert-nodes(xs:QName("ns:test2"), <b/>);
  dml:insert-nodes(xs:QName("ns:test2"), (<c/>, <d/>, <e/>));

  try {                                                                              
      dml:collection(xs:QName("ns:test2"),                                            
                     xs:anyURI("urn:uuid:00000000-0000-0000-0000-000000000000"),
                     0);                                                   
      fn:error(); (: has to fail :)                                                  
  }                                                                                  
  catch zerr:ZSTR0066                                                                
  {                                                                                  
    (: all ok :)                                                                     
  }

  (
    local:order(dml:collection(xs:QName("ns:test2"), 3)), <delim/>,
    local:order(dml:collection(xs:QName("ns:test2"), -1)), <delim/>,
    let $ref := ref:node-reference(dml:collection(xs:QName("ns:test2"))[3])
    return local:order(dml:collection(xs:QName("ns:test2"), $ref, 0))
  )
};

local:test()
