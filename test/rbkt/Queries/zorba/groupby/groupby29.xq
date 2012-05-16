(: Explicit shadowing should be valid :)
for $x in (1,2,3,4,5,6,7,8,9)
let $kind := $x mod 3
group by $kind := $kind * ($x mod 2)
return <numbers group="{$kind}">{$x}</numbers>
