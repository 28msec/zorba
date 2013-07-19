import module namespace r = "http://zorba.io/modules/random";

count((for $i in 1 to 10 return r:random(10), r:random())) eq 101
