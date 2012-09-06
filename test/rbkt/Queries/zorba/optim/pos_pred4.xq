(: Should not optimize :)

for $x at $p in (1, 2, 3, 4, 5, 6, 7, 8, 9, 0)
count $c
where $p = 4
return <res>{$x, $c}</res>,
"

",

for $x in subsequence((1, 2, 3, 4, 5, 6, 7, 8, 9, 0), 4, 1)
count $c
return <res>{$x, $c}</res>
