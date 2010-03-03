import module namespace xqddf-test = "http://www.zorba-xquery.com/modules/xqddf/test" at "xqddf_prolog.xqlib";
import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";

xqddf:create-collection($xqddf-test:white-collection);

xqddf:activate-integrity-constraint($xqddf-test:eic1);

block{
<newline>
</newline>
},
block{
for $i in fn:doc("auction.xml")//item
return fn:string(($i/description/parlist/listitem/text)[1]);
},
block{
<newline> a
</newline>
},
block{
for $i in fn:doc("auction.xml")//item
return 
   block{block{fn:string(($i/description/parlist/listitem/text)[1]);},
   block{ xqddf:insert-nodes($xqddf-test:white-collection, (copy $copyi := $i modify () return $copyi));};};
},
block{
xqddf:delete-nodes($xqddf-test:white-collection, xqddf:collection($xqddf-test:white-collection)[1]);
},
block{
<newline> a
</newline>
},
block{
xqddf:collection($xqddf-test:white-collection)/description/parlist/listitem/text;
};
