import module namespace xqddf-test = "http://www.zorba-xquery.com/modules/xqddf/test" at "xqddf_prolog.xqlib";
import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace index_ddl = "http://www.zorba-xquery.com/modules/store/static/indexes/ddl";
import module namespace index_dml = "http://www.zorba-xquery.com/modules/store/static/indexes/dml";


ddl:create($xqddf-test:white-collection);

index_ddl:create($xqddf-test:index2);

for $i in fn:doc("auction.xml")//item
return 
    dml:insert-nodes($xqddf-test:white-collection, (copy $copyi := $i modify () return $copyi));


index_dml:refresh-index($xqddf-test:index2);
(:xqddf:collection($xqddf-test:white-collection);:)

index_dml:probe-index-point-value($xqddf-test:index2, 2)[@id="item2"]
