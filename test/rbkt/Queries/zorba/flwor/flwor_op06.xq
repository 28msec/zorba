(: Should not optimize :)

for $x at $p in (<a grp="2">1</a>, <a grp="1">2</a>, <a grp="2">3</a>)
let $g := $x/@grp
group by $g
where $p = 2
return <grp>{$x/data()}</grp>
