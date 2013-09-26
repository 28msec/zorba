import module namespace s = "http://zorba.io/modules/string";

s:analyze-string( "abab
bbaa", "(ab|a)$", "m" )
