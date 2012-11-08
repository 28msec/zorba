

declare variable $doc := 
<doc>
<a><b i="1"/><b i="2"/></a>
<a><b i="3"/></a>
</doc>;

for $x in $doc/a
let $i := $x//@i
group by $i
return <group><i>{$i}</i>{$x}</group>
,
"
"

