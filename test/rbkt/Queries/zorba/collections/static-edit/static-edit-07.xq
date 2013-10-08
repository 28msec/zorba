import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";
import module namespace index_ddl = "http://zorba.io/modules/store/static/indexes/ddl";
import module namespace index_dml = "http://zorba.io/modules/store/static/indexes/dml";
import module namespace ref = "http://zorba.io/modules/reference";

import module namespace ns = "http://www.example.com/example"
  at "static-edit-collection_with_index.xqdata";

ddl:create(xs:QName("ns:collection"));

index_ddl:create(xs:QName("ns:index"));

dml:insert(xs:QName("ns:collection"), (<a id="1"/>, <b id="2"/>, <c id="3"/>));

variable $old := dml:collection(xs:QName("ns:collection"))[2];

dml:edit(dml:collection(xs:QName("ns:collection"))[2], <d id="4"/>);

variable $new := dml:collection(xs:QName("ns:collection"))[2];

index_dml:probe-index-point-value(xs:QName("ns:index"), 1),
index_dml:probe-index-point-value(xs:QName("ns:index"), 2),
index_dml:probe-index-point-value(xs:QName("ns:index"), 3),
index_dml:probe-index-point-value(xs:QName("ns:index"), 4)
