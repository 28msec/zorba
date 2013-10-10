import module namespace xqddf-test = "http://www.zorba-xquery.com/modules/xqddf/test" at "xqddf_prolog.xqlib";
import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";
import module namespace ic_ddl = "http://zorba.io/modules/store/static/integrity-constraints/ddl";

ddl:create($xqddf-test:white-collection);
ddl:create($xqddf-test:blue-collection);

ic_ddl:activate($xqddf-test:ric1);

{
<newline>
</newline>
}
,
{
for $i in fn:doc("auction.xml")//item
return $i/name
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
    { $i/name },
    { dml:insert($xqddf-test:blue-collection,
                 (copy $copyi := $i modify () return $copyi));
      ()
    },
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
dml:delete(dml:collection($xqddf-test:white-collection)[1]);
()
}
,
{
dml:collection($xqddf-test:white-collection)/name
}
