import module namespace ref = "http://zorba.io/modules/reflection";

for $f in (xs:QName("fn:max"), xs:QName("fn:min"))
return ref:invoke($f, (1, 2, 3))
