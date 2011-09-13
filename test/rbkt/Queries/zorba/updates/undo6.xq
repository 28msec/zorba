import module namespace m = 'xqueryzorba.org/test/xqddf/ic' at '../xqddf/ic.xqlib';

import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";

import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";

import module namespace dddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";

import module namespace ic_ddl = "http://www.zorba-xquery.com/modules/store/static/integrity_constraints/ddl";


declare variable $test:=
<root>
<t1>a<a/>b<a/>c<a/>d<a/>e</t1>
<t2><a/>ab<a/>c<a/>d<a/>e</t2>
<t3>a<a/>b<a/>c<a/>de<a/></t3>
<t4><a/>ab<a/>c<a/>de<a/></t4>
</root>;

declare variable $test2:=
<root>
<t1>a<a/>b<a/>c<a/>d<a/>e</t1>
<t2><a/>ab<a/>c<a/>d<a/>e</t2>
<t3>a<a/>b<a/>c<a/>de<a/></t3>
<t4><a/>ab<a/>c<a/>de<a/></t4>
</root>;

declare variable $test3:=
<root>
<t1>cde</t1>
<t2>ab</t2>
<t3>a<c/>de</t3>
<t4>ab<c/>e</t4>
</root>;

declare variable $test4:=
<root>
<t1>a<a/>b<a/>c<a/>d<a/>e</t1>
</root>;


declare updating function local:update()
{
(
delete node $test//a,

for $a in $test2//a
return
replace node $a with (),

insert node "ab" as first into $test3/t1,
insert node "cde" as last into $test3/t2,
insert node "b" before $test3/t3/c,

insert node "d" after $test3/t4/c,

insert node "x" before $test4/t1/a[1],
insert node "x" after $test4/t1/a[1],
insert node "x" before $test4/t1/a[2],
insert node "x" after $test4/t1/a[2],
insert node "x" before $test4/t1/a[3],
insert node "x" after $test4/t1/a[3],
insert node "x" before $test4/t1/a[4],
insert node "x" after $test4/t1/a[4]
)

};


ddl:create($m:empc);

ic_ddl:activate(xs:QName("m:ic_simple"));

try
{
  (
  local:update()
  ,
  dml:insert-nodes($m:empc, <emp><salary>600</salary></emp>)
  );
}
catch * 
{
}


(
$test,
element {"text-nodes"}{count($test/*/text())},
$test2,
element {"text-nodes"}{count($test2/*/text())},
$test3,
element {"text-nodes"}{count($test3/*/text())},
$test4,
element {"text-nodes"}{count($test4/*/text())}
)
