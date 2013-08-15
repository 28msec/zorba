import module namespace f = "http://expath.org/ns/file";
import module namespace b = "http://zorba.io/modules/base64";

b:decode(xs:base64Binary(f:read-text(resolve-uri("iso-8859-1.txt"))), "ISO-8859-1")

