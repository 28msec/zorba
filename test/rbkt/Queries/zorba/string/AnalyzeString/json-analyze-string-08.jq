(: read text file with 240 times aaa...aabbb....bb :)
import module namespace file = "http://expath.org/ns/file";
import module namespace s = "http://zorba.io/modules/string";

s:analyze-string( file:read-text( fn:resolve-uri( "text_test1.txt" ) ), "c" )
