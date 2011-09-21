import module namespace ref = "http://www.zorba-xquery.com/modules/reflection";

ref:invoke(xs:QName("fn:sum"), ((1 to 100)[.<5], 2))
