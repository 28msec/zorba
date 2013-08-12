import module namespace f = "http://expath.org/ns/file";
import module namespace s = "http://zorba.io/modules/string";

s:split(f:read-text(fn:resolve-uri("token03.txt")), "bc"),
s:split(s:materialize(f:read-text(fn:resolve-uri("token03.txt"))), "bc")
