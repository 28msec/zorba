
import module namespace num = "http://www.w3.org/TestModules/numbers" at "numbers.xqlib";

import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace iddl = "http://www.zorba-xquery.com/modules/store/static/indexes/ddl";
import module namespace idml = "http://www.zorba-xquery.com/modules/store/static/indexes/dml";


ddl:create($num:collname);

dml:insert-nodes($num:collname, doc("numbers.xml"));

iddl:create($num:idx-g-h-long);
iddl:create($num:idx-g-t-long);

"
-------------------------------------
Probing long keys with a double
-------------------------------------

probe 1 (eq - hash):

",
for $num in idml:probe-index-point-general($num:idx-g-h-long, 
                                           9223372036854770688E0)
return $num,

"

probe 2 (eq - hash):

",
for $num in idml:probe-index-point-general($num:idx-g-h-long, 
                                           9223372036854770689E0)
return $num,

"

probe 3 (gt):

",
for $num in idml:probe-index-range-value($num:idx-g-t-long, 
                                         9223372036854770178E0,
                                         0E0,
                                         fn:true() , fn:false(),
                                         fn:false(), fn:false())
return $num,

"

probe 4 (ge):

",
for $num in idml:probe-index-range-value($num:idx-g-t-long, 
                                         9223372036854770178E0,
                                         0E0,
                                         fn:true() , fn:false(),
                                         fn:true(), fn:false())
return $num,

"

"

(:
,
for $node in dml:collection(xs:QName("num:numbers"))//xs_long
where xs:long($node//@num) ge 9223372036854770178E0
return $node,
"
"
:)


