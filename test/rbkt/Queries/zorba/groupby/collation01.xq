

for $x in ("AA", "aa")
group by $x collation "http://www.zorba-xquery.com/collations/SECONDARY/en/EN", $x
return <res>{$x}</res>
,
"
"
,
for $x in ("AA", "aa")
group by $x, $x collation "http://www.zorba-xquery.com/collations/SECONDARY/en/EN"
return <res>{$x}</res>
,
"
"
