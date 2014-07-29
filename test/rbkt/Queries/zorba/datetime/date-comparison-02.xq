for $x in (xs:date("2010-10-10"), xs:date("1997-01-01+12:00"), xs:date("1997-01-02+12:00"))
for $y in (adjust-date-to-timezone(xs:date("2010-10-10"), implicit-timezone()), xs:date("1997-01-01-12:00"))
where $x = $y
return $x