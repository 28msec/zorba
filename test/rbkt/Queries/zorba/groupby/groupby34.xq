(:
   No grouping variable declared in the group by clause
:)
 
for $x in 1 to 100
group by $x mod 10
return string(text{$x})
