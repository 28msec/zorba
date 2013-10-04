import module namespace ref = "http://zorba.io/modules/reflection";

ref:invoke(xs:QName("fn:sum"), ((1 to 100)[.<5], 2))
