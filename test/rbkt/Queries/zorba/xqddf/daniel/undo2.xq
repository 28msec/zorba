import module namespace xqddf-test = "http://www.zorba-xquery.com/modules/xqddf/test" at "xqddf_prolog.xqlib";
import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";

xqddf:create-collection($xqddf-test:white-collection);

block{
<newline>
</newline>
},
block{

for $i in fn:doc("auction.xml")//item
return 
    xqddf:insert-nodes($xqddf-test:white-collection, (copy $copyi := $i modify () return $copyi));


xqddf:create-index($xqddf-test:index1);
},
block{
xqddf:insert-nodes($xqddf-test:white-collection, <item><location>Earth3</location></item>);
},
block{
xqddf:probe-index-point($xqddf-test:index1, "Earth3")[1]; 
},
block{
try{
    (xqddf:insert-nodes($xqddf-test:white-collection, <item><location>Earth</location></item>),
    xqddf:insert-nodes($xqddf-test:white-collection, ""));
}
catch * { "
cannot insert empty item in white collection"}
},
block{
<newline> a
</newline>
},
block{
xqddf:probe-index-point($xqddf-test:index1, "Earth")[1]; 
};
