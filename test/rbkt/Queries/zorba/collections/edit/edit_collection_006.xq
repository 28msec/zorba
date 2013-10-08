import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";
import module namespace ref = "http://zorba.io/modules/reference";

import module namespace ns = "http://www.example.com/example" at "../collection_001.xqdata";

ddl:create(xs:QName("ns:collection"));

dml:insert(xs:QName("ns:collection"), (<a/>, <b/>, <c/>));

variable $old := dml:collection(xs:QName("ns:collection"))[2];

dml:edit(dml:collection(xs:QName("ns:collection"))[2], <d/>);

variable $new := dml:collection(xs:QName("ns:collection"))[2];

$old is $new
