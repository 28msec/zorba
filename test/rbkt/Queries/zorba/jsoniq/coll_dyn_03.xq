
import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";

import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

declare namespace err = "http://www.w3.org/2005/xqt-errors";

declare namespace xqsx = "http://www.zorba-xquery.com/zorba/scripting";

declare variable $coll1 := xs:QName("collection1");

ddl:create($coll1, (<a/>, { "p1":1, "p2":2 }, [1, 2, 3]));

(
["
XXX-01"]
,
dml:collection($coll1)[. instance of object()]
,
["
XXX-02"]
,
xqsx:apply((dml:insert-first($coll1, { "p1":3, "p2":4 }),
            dml:insert-last($coll1, (<b/>, { "p1" : 5 }))))
,
(: { "p1":3, "p2":4 }, <a/>, { "p1":1, "p2":2 }, { }, [1, 2, 3], <b/>, { "p1" : 5 } :)
["
XXX-03"]
,
dml:collection($coll1)[. instance of object()]
,
["
XXX-04"]
,
{
"index" :
(
let $o := dml:collection($coll1)[. instance of object()][2]
return dml:index-of($o)
)
}
,
["
XXX-05"]
,
xqsx:apply(
let $n := dml:collection($coll1)[. instance of node()][2]
return (dml:insert-before($coll1, $n, { "p1":6 }),
        dml:insert-after($coll1, $n, []))
)
(: { "p1":3, "p2":4 }, <a/>, { "p1":1, "p2":2 }, { }, [1, 2, 3], { "p1":6 }, <b/>, [], { "p1" : 5 } :)
,
["
XXX-06"]
,

dml:collection($coll1)[. instance of json-item()]
,
["
XXX-07"],
{
variable $items := subsequence(dml:collection($coll1), 2, 2);
dml:delete($items);
()
}
,
(: { "p1":3, "p2":4 }, { }, [1, 2, 3], { "p1":6 }, <b/>, [], { "p1" : 5 } :)
["
XXX-08"]
,
[ count(dml:collection($coll1)[. instance of node()]) ]
,
["
XXX-09"]
,
dml:collection($coll1)[. instance of json-item()]
,
["
XXX-10"]
,
{
dml:delete-nodes-last($coll1, 2);
()
}
,
["
XXX-11"],
dml:collection($coll1)[. instance of json-item()]
,
["
"]
)



