import module namespace xqddf-test = "http://www.zorba-xquery.com/modules/xqddf/test" at "xqddf_prolog.xqlib";
import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";

init:create-collection($xqddf-test:white-collection);
init:create-collection($xqddf-test:blue-collection);

init:activate-integrity-constraint($xqddf-test:ric1);

block{
<newline>
</newline>
},
block
{
for $i in fn:doc("auction.xml")//item
return $i/name;
},
block{
<newline> a
</newline>
},
block{
for $i in fn:doc("auction.xml")//item
return 
    block{block{$i/name;},
    block{manip:insert-nodes($xqddf-test:blue-collection, (copy $copyi := $i modify () return $copyi));},
    block{manip:insert-nodes($xqddf-test:white-collection, (copy $copyi := $i modify () return $copyi));};};
},
block{
try{
    (manip:insert-nodes($xqddf-test:blue-collection, (fn:doc("auction.xml")//item)[1]),
    manip:delete-nodes(manip:collection($xqddf-test:blue-collection)[1]));
}
catch * { "
cannot delete first item in blue collection"}
},
block{
<newline> a
</newline>
},
block{
manip:collection($xqddf-test:white-collection)/name;
},
block{
<newline> a
</newline>
},
block{
manip:collection($xqddf-test:blue-collection)/name;
};
