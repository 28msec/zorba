
import module namespace num = "http://www.w3.org/TestModules/numbers" at "numbers.xqlib";

import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace iddl = "http://www.zorba-xquery.com/modules/store/static/indexes/ddl";
import module namespace idml = "http://www.zorba-xquery.com/modules/store/static/indexes/dml";


ddl:create($num:collname);

dml:insert-nodes($num:collname, doc("numbers.xml"));

iddl:create($num:idx-g-h-long);

"
-------------------------------------
Probing long keys with a double
-------------------------------------

probe 1:

",
for $num in idml:probe-index-point-general($num:idx-g-h-long, 
                                           9223372036854770688E0)
return $num,

"
"
(:

,
for $node in dml:collection(xs:QName("num:numbers"))//xs_long
where xs:long($node//@num) eq 9223372036854770688E0
return $node

:)
