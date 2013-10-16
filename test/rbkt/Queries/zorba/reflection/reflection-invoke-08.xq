import module namespace ref = "http://zorba.io/modules/reflection";

let $f := xs:QName("fn:tokenize")
return ref:invoke($f, "Str1,Str2,Str3", ",")
