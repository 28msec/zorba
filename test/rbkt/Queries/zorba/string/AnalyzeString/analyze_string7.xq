(: read text file with 240 times aaa...aabbb....bb :)
import module namespace file = "http://www.zorba-xquery.com/modules/file";

fn:analyze-string(file:read-text(fn:resolve-uri("text_test1.txt")), "(a+b+)+")