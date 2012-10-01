import module namespace xqddf-test = "http://www.zorba-xquery.com/modules/xqddf/test" at "xqddf_prolog.xqlib";
import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace index_ddl = "http://www.zorba-xquery.com/modules/store/static/indexes/ddl";
import module namespace index_dml = "http://www.zorba-xquery.com/modules/store/static/indexes/dml";


ddl:create($xqddf-test:white-collection);

for $i in fn:doc("auction.xml")//item
return 
    dml:insert-nodes($xqddf-test:white-collection, (copy $copyi := $i modify () return $copyi));


index_ddl:create($xqddf-test:index1);

(: dml:collection($xqddf-test:white-collection)[location eq "United States"] :)

index_dml:probe-index-point-value($xqddf-test:index1, "United States")[@id="item0"]
