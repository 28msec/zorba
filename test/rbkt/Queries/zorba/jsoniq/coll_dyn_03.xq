
import module namespace ddl = "http://www.zorba-xquery.com/modules/store/jsoniq/dynamic/collections/ddl";

import module namespace dml = "http://www.zorba-xquery.com/modules/store/jsoniq/dynamic/collections/dml";

declare namespace err = "http://www.w3.org/2005/xqt-errors";

declare namespace xqsx = "http://www.zorba-xquery.com/zorba/scripting";

declare variable $coll1 := xs:QName("collection1");

ddl:create($coll1, (<a/>, { "p1":1, "p2":2 }, object {}, [1, 2, 3]));

(
["
"]
,
dml:collection($coll1)[. instance of object()]
,

xqsx:apply((dml:insert-nodes-first($coll1, { "p1":3, "p2":4 }),
            dml:insert-nodes-last($coll1, (<b/>, { "p1" : 5 }))))
,
["
"]
,
dml:collection($coll1)[. instance of object()]
,
["
"]
,
object 
{
"index" :
let $o := dml:collection($coll1)[. instance of object()][2]
return dml:index-of($o)
}
,
["
"]
,
xqsx:apply(
let $n := dml:collection($coll1)[. instance of node()][2]
return (dml:insert-nodes-before($coll1, $n, { "p1":6 }),
        dml:insert-nodes-after($coll1, $n, []))
)
,

dml:collection($coll1)[. instance of json-item()]
,
["
"]
)



