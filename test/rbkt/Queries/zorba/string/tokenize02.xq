import module namespace f = "http://expath.org/ns/file";
import module namespace s = "http://www.zorba-xquery.com/modules/string";

s:split(f:read-text(fn:resolve-uri("token02.txt")), "bc"),
s:split(s:materialize(f:read-text(fn:resolve-uri("token02.txt"))), "bc")
