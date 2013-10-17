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
},

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
},
{
  try
  {
    {
      dml:insert($xqddf-test:blue-collection, <newnode/>);
      dml:delete(dml:collection($xqddf-test:blue-collection)[@id="item0"]);
      ()
    }
  }
  catch * { "
cannot delete first item in blue collection"
  }
}
,
{
<newline> a
</newline>
}
,
{
for $x in dml:collection($xqddf-test:white-collection)
order by number(substring-after($x/@id, "item"))
return $x/name
}
,
{
<newline> a
</newline>
}
,
{
for $x in dml:collection($xqddf-test:blue-collection)
order by number(substring-after($x/@id, "item"))
return $x/name
}
