import module namespace dctx = "http://zorba.io/modules/dctx";
import module namespace file = "http://expath.org/ns/file";

variable $y := dctx:snapshot-id();
file:write-text("test.txt", "test");
$y, dctx:snapshot-id()