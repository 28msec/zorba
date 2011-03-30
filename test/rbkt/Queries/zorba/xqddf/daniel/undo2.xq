import module namespace xqddf-test = "http://www.zorba-xquery.com/modules/xqddf/test" at "xqddf_prolog.xqlib";
import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";

init:create-collection($xqddf-test:white-collection);

block{
<newline>
</newline>
},
block{

for $i in fn:doc("auction.xml")//item
return 
    manip:insert-nodes($xqddf-test:white-collection, (copy $copyi := $i modify () return $copyi));


init:create-index($xqddf-test:index1);
},
block{
manip:insert-nodes($xqddf-test:white-collection, <item><location>Earth3</location></item>);
},
block{
manip:probe-index-point-value($xqddf-test:index1, "Earth3")[1]; 
},
block{
try{
    (manip:insert-nodes($xqddf-test:white-collection, <item><location>Earth</location></item>),
    manip:insert-nodes($xqddf-test:white-collection, ""));
}
catch * { "
cannot insert empty item in white collection"}
},
block{
<newline> a
</newline>
},
block{
manip:probe-index-point-value($xqddf-test:index1, "Earth")[1]; 
};
