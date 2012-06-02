for $x in 1 to 9
let $kind := $x
group by $kind := $kind mod 3, $even := $kind * ($x mod 2)
return <numbers kind="{$kind}" even="{$even}">{$x}</numbers>
