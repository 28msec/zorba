import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";

import module namespace ns = "http://www.example.com/example" at "../collection_002.xqdata";

variable $contents;

ddl:create(xs:QName("ns:collection"));
ddl:create(xs:QName("ns:collection2"));

dml:insert-nodes(
  xs:QName("ns:collection"),
  for $i in 1 to 10 return <a>{$i}</a>
);

dml:insert-nodes(
  xs:QName("ns:collection2"),
  for $i in 1 to 10 return <b>{$i}</b>
);

$contents := (dml:collection(xs:QName("ns:collection")), dml:collection(xs:QName("ns:collection2")));

(dml:truncate(xs:QName("ns:collection")), dml:truncate(xs:QName("ns:collection2")));

$contents := ($contents, dml:collection(xs:QName("ns:collection")), dml:collection(xs:QName("ns:collection")));

$contents
