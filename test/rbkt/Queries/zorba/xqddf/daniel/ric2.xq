import module namespace xqddf-test = "http://www.zorba-xquery.com/modules/xqddf/test" at "xqddf_prolog.xqlib";
import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";

init:create-collection($xqddf-test:white-collection);
init:create-collection($xqddf-test:blue-collection);

init:activate-integrity-constraint($xqddf-test:ric1);

{
<newline>
</newline>
},

{
for $i in fn:doc("auction.xml")//item
return $i/name;
},
{
<newline> a
</newline>
},
{
for $i in fn:doc("auction.xml")//item
return 
    {{$i/name},
    {manip:insert-nodes($xqddf-test:blue-collection, (copy $copyi := $i modify () return $copyi));},
    {manip:insert-nodes($xqddf-test:white-collection, (copy $copyi := $i modify () return $copyi));}}
},
{
<newline> a
</newline>
},
{
manip:delete-nodes(manip:collection($xqddf-test:blue-collection)[1]);
},
{
manip:collection($xqddf-test:white-collection)/name;
}
