jsoniq version "1.0";
import module namespace http="http://zorba.io/modules/http-client";

(: value is "hello there" in base64 :)
variable $arg as xs:base64Binary := "aGVsbG8gdGhlcmUK" cast as xs:base64Binary;
variable $result :=
  http:post("http://zorbatest.28.io:8080/cgi-bin/test-text", $arg);

$result.body.content

