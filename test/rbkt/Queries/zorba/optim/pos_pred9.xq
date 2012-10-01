(: Should NOT optimize :)

declare variable $g as xs:integer := -4;

for $x at $p in (7, 2, 34, 4, 1, 3, 5, 9, 8, 0)
where $p = $x
return $x
