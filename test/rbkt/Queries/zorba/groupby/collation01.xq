

for $x in ("AA", "aa")
group by $x collation "http://zorba.io/collations/SECONDARY/en/EN", $x
return <res>{$x}</res>
,
"
"
,
for $x in ("AA", "aa")
group by $x, $x collation "http://zorba.io/collations/SECONDARY/en/EN"
return <res>{$x}</res>
,
"
"
