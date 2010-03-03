import module namespace xqddf-test = "http://www.zorba-xquery.com/modules/xqddf/test" at "xqddf_prolog.xqlib";
import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";

xqddf:create-collection($xqddf-test:white-collection);
xqddf:create-collection($xqddf-test:blue-collection);

xqddf:activate-integrity-constraint($xqddf-test:ric1);

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
    block{xqddf:insert-nodes($xqddf-test:blue-collection, (copy $copyi := $i modify () return $copyi));},
    block{xqddf:insert-nodes($xqddf-test:white-collection, (copy $copyi := $i modify () return $copyi));};};
},
block{
<newline> a
</newline>
},
block{
xqddf:delete-nodes($xqddf-test:white-collection, xqddf:collection($xqddf-test:white-collection)[1]);
replace value of node xqddf:collection($xqddf-test:blue-collection)[1]/name 
        with "gaze wages proving english ";
},
block{
xqddf:collection($xqddf-test:white-collection)/name;
},
block{
<newline> a
</newline>
},
block{
xqddf:collection($xqddf-test:blue-collection)/name;
};
