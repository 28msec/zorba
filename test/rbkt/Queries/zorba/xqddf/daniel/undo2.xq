import module namespace xqddf-test = "http://www.zorba-xquery.com/modules/xqddf/test" at "xqddf_prolog.xqlib";
import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";
import module namespace index_ddl = "http://zorba.io/modules/store/static/indexes/ddl";
import module namespace index_dml = "http://zorba.io/modules/store/static/indexes/dml";

ddl:create($xqddf-test:white-collection);

{
<newline>
</newline>
}
,
{

for $i in fn:doc("auction.xml")//item
return 
    dml:insert($xqddf-test:white-collection,
               (copy $copyi := $i modify () return $copyi));

index_ddl:create($xqddf-test:index1);

()
}
,
{
dml:insert($xqddf-test:white-collection, <item><location>Earth3</location></item>);
()
}
,
{
index_dml:probe-index-point-value($xqddf-test:index1, "Earth3")[1]
}
,
{
try
{
  {
    dml:insert($xqddf-test:white-collection,
               <item><location>Earth</location></item>);
    dml:insert($xqddf-test:white-collection, "");
    ()
  }
}
catch * { "
cannot insert empty item in white collection"}
}
,
{
<newline> a
</newline>
}
,
{
index_dml:probe-index-point-value($xqddf-test:index1, "Earth")[1];
()
}
