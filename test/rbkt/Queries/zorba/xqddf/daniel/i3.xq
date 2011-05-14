import module namespace xqddf-test = "http://www.zorba-xquery.com/modules/xqddf/test" at "xqddf_prolog.xqlib";
import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";


init:create-collection($xqddf-test:white-collection);

init:create-index($xqddf-test:index2);

for $i in fn:doc("auction.xml")//item
return 
    manip:insert-nodes($xqddf-test:white-collection, (copy $copyi := $i modify () return $copyi));


manip:refresh-index($xqddf-test:index2);
(:xqddf:collection($xqddf-test:white-collection);:)

manip:probe-index-point-value($xqddf-test:index2, 2)[1]
