(: Explicit shadowing should be valid :)
for $x in 1 to 9
let $kind := $x mod 3
group by $kind := $kind * ($x mod 2)
return <numbers group="{$kind}">{$x}</numbers>
