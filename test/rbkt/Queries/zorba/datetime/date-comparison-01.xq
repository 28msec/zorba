for $x in (xs:date("2010-10-10"))
for $y in (adjust-date-to-timezone(xs:date("2010-10-10"), implicit-timezone()))
where $x = $y
return $x