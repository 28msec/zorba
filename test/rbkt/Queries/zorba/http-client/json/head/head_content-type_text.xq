jsoniq version "1.0";
import module namespace http="http://zorba.io/modules/http-client";

declare namespace exp="http://expath.org/ns/http-client";

http:head("http://zorbatest.lambda.nu:8080/cgi-bin/test-text").headers("Content-Type")