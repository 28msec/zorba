import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";
import module namespace ref = "http://www.zorba-xquery.com/modules/node-reference";

declare namespace ann = "http://www.zorba-xquery.com/annotations";
declare namespace ns = "http://www.zorba-xquery.com/test";

declare %ann:sequential function local:test()
{
  ddl:create(xs:QName("ns:test2"));
  dml:insert-nodes-last(xs:QName("ns:test2"), <a/>);
  dml:insert-nodes-last(xs:QName("ns:test2"), <b/>);
  dml:insert-nodes-last(xs:QName("ns:test2"), (<c/>, <d/>, <e/>));
  (
    dml:collection(xs:QName("ns:test2"), 3), <delim/>,
    dml:collection(xs:QName("ns:test2"), -1), <delim/>,
    let $ref := ref:node-reference(dml:collection(xs:QName("ns:test2"))[3])
    return dml:collection(xs:QName("ns:test2"), $ref, 0)
  )
};

local:test()
