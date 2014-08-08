import module namespace refl = "http://zorba.io/modules/reflection";

for $i in 1 to 3
return refl:eval($i||"+"||$i)