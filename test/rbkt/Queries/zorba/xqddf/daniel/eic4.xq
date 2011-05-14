import module namespace xqddf-test = "http://www.zorba-xquery.com/modules/xqddf/test" at "xqddf_prolog.xqlib";
import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";

init:create-collection($xqddf-test:white-collection);

init:activate-integrity-constraint($xqddf-test:eic1);

{
<newline>
</newline>
},
{
for $i in fn:doc("auction.xml")//item
return fn:string(($i/description/parlist/listitem/text)[1])
},
{
<newline> a
</newline>
},
{
for $i in fn:doc("auction.xml")//item
return 
   {{fn:string(($i/description/parlist/listitem/text)[1])},
   { manip:insert-nodes($xqddf-test:white-collection, (copy $copyi := $i modify () return $copyi));}}
},
{
manip:delete-nodes(manip:collection($xqddf-test:white-collection)[1]);
},
{
<newline> a
</newline>
},
{
manip:collection($xqddf-test:white-collection)/description/parlist/listitem/text
}
