import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";
import module namespace ref = "http://zorba.io/modules/reference";

declare namespace ann = "http://zorba.io/annotations";
declare namespace ns = "http://www.zorba-xquery.com/test";

declare %ann:sequential function local:test()
{
  ddl:create(xs:QName("ns:test2"));
  dml:insert-nodes-last(xs:QName("ns:test2"), <a/>);
  dml:insert-nodes-last(xs:QName("ns:test2"), <b/>);
  dml:insert-nodes-last(xs:QName("ns:test2"), (<c/>, <d/>, <e/>));

  dml:collection(
    xs:QName("ns:test2"),
    xs:anyURI("urn:uuid:aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa"), 0)
};

local:test()
