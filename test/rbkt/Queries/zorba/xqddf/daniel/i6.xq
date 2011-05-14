import module namespace xqddf-test = "http://www.zorba-xquery.com/modules/xqddf/test" at "xqddf_prolog.xqlib";
import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";


init:create-collection($xqddf-test:white-collection);

init:create-index($xqddf-test:index1);
init:create-index($xqddf-test:index2);

for $i in fn:doc("auction.xml")//item
return 
    manip:insert-nodes($xqddf-test:white-collection, (copy $copyi := $i modify () return $copyi));


manip:refresh-index($xqddf-test:index2);
(:xqddf:collection($xqddf-test:white-collection);:)
{
<newline>
</newline>
},

{
manip:probe-index-point-value($xqddf-test:index1, "United States")[1]/name
},

{
manip:probe-index-range-value($xqddf-test:index2, 1, 3, fn:true(), fn:true(), fn:true(), fn:false())[1]
},
{
rename node manip:collection($xqddf-test:white-collection)[1]/location as "location2";
},
{
<newline> a
</newline>
},

{
manip:probe-index-point-value($xqddf-test:index1, "United States")[1]/name
}
