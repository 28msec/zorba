(:
  test for bug #3107911
  make sure user errors are also caught if raised from a function
  (potentially contained in a different module)
:)


import module namespace lib = 'http://www.example.com/lib' at "trycatch8.xqlib";

try {
  lib:error()
} catch * ($error_code, $desc, $obj) {
  $error_code, $desc, $obj
}
