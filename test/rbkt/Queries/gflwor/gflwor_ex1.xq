for $x in (5,6,7,1,2,3,4)
where $x < 4
for $y in (4,9,6,8,2)
let $z := $x * $y
where $z > 20
return 
<value x="{$x}" y="{$y}">{$z}</value>
