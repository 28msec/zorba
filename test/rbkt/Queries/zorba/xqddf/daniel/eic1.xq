import module namespace xqddf-test = "http://www.zorba-xquery.com/modules/xqddf/test" at "xqddf_prolog.xqlib";
import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";
import module namespace ic_ddl = "http://zorba.io/modules/store/static/integrity-constraints/ddl";

ddl:create($xqddf-test:white-collection);

ic_ddl:activate($xqddf-test:eic1);

{
<newline>
</newline>
}
,
{
for $i in fn:doc("auction.xml")//item
return fn:string(($i/description/parlist/listitem/text)[1])
}
,
{
<newline> a
</newline>
}
,
{
for $i in fn:doc("auction.xml")//item
return 
  {
    { fn:string(($i/description/parlist/listitem/text)[1]) },
    { dml:insert($xqddf-test:white-collection,
      (copy $copyi := $i modify () return $copyi));
      ()
    }
  }
}
,
{
<newline> a
</newline>
}
,
{
dml:collection($xqddf-test:white-collection)/description/parlist/listitem/text
}
