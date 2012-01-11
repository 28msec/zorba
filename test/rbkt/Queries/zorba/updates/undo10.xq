import module namespace m = 'xqueryzorba.org/test/xqddf/ic' at '../xqddf/ic.xqlib';
import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace ic_ddl = "http://www.zorba-xquery.com/modules/store/static/integrity_constraints/ddl";
import module namespace schema = "http://www.zorba-xquery.com/modules/schema";
import module namespace u = "http://www.zorba-xquery.com/test/undo/utils" at "utils.xqlib";
import schema namespace s="http://www.zorba-xquery.org/schema" at "subst.xsd";

declare revalidation lax;

variable $x:=
validate{
<items-a xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xmlns="http://www.zorba-xquery.org/schema">
  <number>111</number>
</items-a>};

ddl:create($m:empc);

ic_ddl:activate(xs:QName("m:ic_simple"));

try
{
( 
  rename node $x as QName("http://www.zorba-xquery.org/schema", "items-b"),

  dml:insert-nodes($m:empc, <emp><salary>600</salary></emp>)
);
}
catch *
{
}

u:dump-types($x)
