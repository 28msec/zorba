declare namespace opt = "http://www.zorba-xquery.com/options/optimizer";

declare copy-namespaces preserve, no-inherit;

declare option opt:enable "for-serialization-only";

declare variable $doc1 :=
<doc1 xmlns:p1="www.foo1.com">
<a/>
</doc1>;


let $doc2 := <doc2 xmlns:p2="www.foo2.com">{$doc1/a}</doc2>
return
$doc2/a
,
"
"
