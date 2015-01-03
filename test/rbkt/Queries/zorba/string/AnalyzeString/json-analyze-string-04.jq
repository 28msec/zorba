jsoniq version "1.0";
import module namespace s = "http://zorba.io/modules/string";

s:analyze-string( "abab\nbabba", "(b)a", "m" )
