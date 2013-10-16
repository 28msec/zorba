import module namespace refl = "http://zorba.io/modules/reflection";

declare namespace myns="a";

declare variable $myns:g := 42;

let $y := 1
let $myns:x := $myns:g 
return 
  refl:eval
  (
    "declare namespace myns1='a';

    declare function local:f() { 11 + $myns:g + $y};

    $myns1:x + local:f()"
  )
