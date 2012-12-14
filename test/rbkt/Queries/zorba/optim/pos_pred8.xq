(: Should optimize into better flwor statement :)

declare variable $g as xs:integer := -4;

for $x at $p in (1, 2, 3, 4, 5, 6, 7, 8, 9, 0)
where $p = $g
return $x
