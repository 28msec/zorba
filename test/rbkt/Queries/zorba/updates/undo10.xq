import module namespace m = 'xqueryzorba.org/test/xqddf/ic' at '../xqddf/ic.xqlib';
import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";
import module namespace ic_ddl = "http://zorba.io/modules/store/static/integrity-constraints/ddl";
import module namespace schema = "http://zorba.io/modules/schema";
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

  dml:insert($m:empc, <emp><salary>600</salary></emp>)
);
}
catch *
{
}

u:dump-types($x)
