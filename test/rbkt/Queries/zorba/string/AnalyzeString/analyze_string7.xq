(: read text file with 240 times aaa...aabbb....bb :)
import module namespace file = "http://expath.org/ns/file";

fn:analyze-string(file:read-text(fn:resolve-uri("text_test1.txt")), "(a+b+)+")