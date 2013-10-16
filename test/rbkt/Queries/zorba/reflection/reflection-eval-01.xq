import module namespace reflection = "http://zorba.io/modules/reflection";
import module namespace client = "http://pilman.ch/ns/blubb" at "client.xqlib";

reflection:eval-s("client:tweets1()")
