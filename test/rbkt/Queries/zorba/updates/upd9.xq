
variable $test:=
<root>
<t1>a<a/>b<a/>c<a/>d<a/>e</t1>
<t2><a/>ab<a/>c<a/>d<a/>e</t2>
<t3>a<a/>b<a/>c<a/>de<a/></t3>
<t4><a/>ab<a/>c<a/>de<a/></t4>
</root>;

variable $test2:=
<root>
<t1>a<a/>b<a/>c<a/>d<a/>e</t1>
<t2><a/>ab<a/>c<a/>d<a/>e</t2>
<t3>a<a/>b<a/>c<a/>de<a/></t3>
<t4><a/>ab<a/>c<a/>de<a/></t4>
</root>;

variable $test3:=
<root>
<t1>cde</t1>
<t2>ab</t2>
<t3>a<c/>de</t3>
<t4>ab<c/>e</t4>
</root>;

(
delete node $test//a,

for $a in $test2//a
return replace node $a with (),

insert node "ab" as first into $test3/t1,
insert node "cde" as last into $test3/t2,
insert node "b" before $test3/t3/c,
insert node "d" after $test3/t4/c
);

(
$test,
element {"text-nodes"}{count($test/*/text())},
$test2,
element {"text-nodes"}{count($test2/*/text())},
$test3,
element {"text-nodes"}{count($test3/*/text())}
)
