import module namespace auto = "http://www.zorba-xquery.com/test/indexes/automatic" at "auto.xqlib";

import module namespace cdml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace cddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";

cddl:create(xs:QName("auto:coll"));

cdml:insert-nodes(xs:QName("auto:coll"), <node id="1">blub</node>);
cdml:insert-nodes(xs:QName("auto:coll"), <node id="1">blub</node>);

for $x in cdml:collection(xs:QName("auto:coll"))
return <a>{ $x/@id }</a>
