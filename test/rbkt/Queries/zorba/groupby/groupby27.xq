for $x in (1,2,3,4,5,6,7,8,9)
let $kind := $x
group by $kind := $kind mod 3, $even := $kind * ($x mod 2)
return <numbers kind="{$kind}" even="{$even}">{$x}</numbers>
