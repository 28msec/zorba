(:
  test for bug #3107911
  make sure user errors are also caught if raised from a function
  (potentially contained in a different module)
:)


declare namespace err="http://www.w3.org/2005/xqt-errors";
import module namespace lib = 'http://www.example.com/lib' at "trycatch8.xqlib";

try {
  lib:error()
} catch * {
  $err:code, $err:description, $err:value
}
