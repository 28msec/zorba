import module namespace ref = "http://www.zorba-xquery.com/modules/reflection";

let $f := xs:QName("fn:tokenize")
return ref:invoke($f, "Str1,Str2,Str3", ",")
