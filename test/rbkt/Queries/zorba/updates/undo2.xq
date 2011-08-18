

import module namespace m = 'xqueryzorba.org/test/xqddf/ic' at '../xqddf/ic.xqlib';

import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";

import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";

import module namespace ic_ddl = "http://www.zorba-xquery.com/modules/store/static/integrity_constraints/ddl";

ddl:create($m:empc);

ic_ddl:activate(xs:QName("m:ic_simple"));

variable $test:=<root>w<a/>x<b/>y<c/>z</root>;

try
{
(
replace node $test/*[1] with "aa",

replace node $test/*[2] with "bb",

dml:insert-nodes($m:empc,
<emp>
<salary>600</salary>
</emp>
)
);
}
catch * 
{
}


$test
