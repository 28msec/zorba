(: The unused non-group var even should be removed :)

for $non-group in 1 to 10
group by $group-var := $non-group mod 5
return $group-var
