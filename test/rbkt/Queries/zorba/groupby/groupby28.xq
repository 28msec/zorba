for $x in 1 to 8
group by $even as xs:integer := $x mod 2
return <numbers even="{$even eq 0}">{$x}</numbers>
