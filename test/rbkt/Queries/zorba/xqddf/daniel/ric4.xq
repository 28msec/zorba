import module namespace xqddf-test = "http://www.zorba-xquery.com/modules/xqddf/test" at "xqddf_prolog.xqlib";
import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace ic_ddl = "http://www.zorba-xquery.com/modules/store/static/integrity_constraints/ddl";

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
},

{
<newline> a
</newline>
},

{
for $i in fn:doc("auction.xml")//item
return 
  {
    { $i/name },
    { dml:insert-nodes($xqddf-test:blue-collection,
                       (copy $copyi := $i modify () return $copyi));
      ()
    },
    { dml:insert-nodes($xqddf-test:white-collection,
                       (copy $copyi := $i modify () return $copyi));
      ()
    }
  }
},

{
<newline> a
</newline>
},

{
dml:delete-nodes(dml:collection($xqddf-test:white-collection)[1]);

replace value of node dml:collection($xqddf-test:blue-collection)[1]/name 
        with "gaze wages proving english ";
()
},

{
dml:collection($xqddf-test:white-collection)/name
},

{
<newline> a
</newline>
},

{
dml:collection($xqddf-test:blue-collection)/name
}
