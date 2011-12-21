import module namespace f = "http://expath.org/ns/file";
import module namespace s = "http://www.zorba-xquery.com/modules/string";

s:tokenize(f:read-text(fn:resolve-uri("token04.txt")), "f"),
s:tokenize(s:materialize(f:read-text(fn:resolve-uri("token04.txt"))), "f")
