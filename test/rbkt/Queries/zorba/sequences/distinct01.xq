fn:distinct-values(
(1 to 300, 
 100 to 400,
 29,
 145,
 20 to 50,
 for $x in (30 to 40) return xs:string($x),
 "foo",
 "bar"))
