(: Test that an exact import with non-0 patch level does not match :)
(: module with no patch level specified. :)
import module namespace vm = "http://zorba-tests.28.io/modules/ver#2.3.5!";

vm:version()

