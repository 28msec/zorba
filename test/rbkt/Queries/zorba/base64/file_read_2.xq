import module namespace f = "http://expath.org/ns/file";
import module namespace b = "http://www.zorba-xquery.com/modules/converters/base64";

variable $enc-file-name := resolve-uri("encoded-text");
variable $dec-file-name := resolve-uri("decoded-text");
variable $encoded := f:read-text($enc-file-name);
variable $decoded := f:read-text($dec-file-name);

$encoded eq xs:string(b:encode($decoded)),
xs:base64Binary($encoded) eq b:encode($decoded),
b:decode(xs:base64Binary($encoded)) eq $decoded
