import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

declare namespace ann = "http://www.zorba-xquery.com/annotations";
declare namespace ns = "http://www.zorba-xquery.com/test";

declare %ann:sequential function local:test()
{
  ddl:create(xs:QName("ns:test2"));
  dml:insert-nodes-last(xs:QName("ns:test2"), <a/>);
  dml:insert-nodes-last(xs:QName("ns:test2"), <b/>);
  dml:insert-nodes-last(xs:QName("ns:test2"), (<c/>, <d/>, <e/>));
  (
    fn:count(dml:collection(xs:QName("ns:test2"), 3)),
    fn:count(dml:collection(xs:QName("ns:test2"), -1)),
    fn:count(dml:collection(xs:QName("ns:test2"), 100))
  )
};

local:test()

