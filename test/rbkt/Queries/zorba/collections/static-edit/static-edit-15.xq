import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";

import module namespace ns = "http://www.example.com/example"
  at "static-edit-collection_with_type.xqdata";

ddl:create(xs:QName("ns:collection"));

dml:insert(xs:QName("ns:collection"), <foo>1</foo> );

dml:edit(dml:collection(xs:QName("ns:collection")), <bar attr="value">test</bar>);

dml:collection(xs:QName("ns:collection"))
