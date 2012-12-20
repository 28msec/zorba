import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";

import module namespace ns = "http://www.example.com/example" at "collection_with_type.xqdata";

ddl:create(xs:QName("ns:collection"));

dml:insert(xs:QName("ns:collection"), <foo>1</foo> );

dml:edit(dml:collection(xs:QName("ns:collection")), <foo attr="value">test</foo>);

dml:collection(xs:QName("ns:collection"))
