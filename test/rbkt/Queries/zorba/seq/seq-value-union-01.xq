import module namespace seq = "http://zorba.io/modules/sequence";

let $s1 := (1, 1, 2, 3)
let $s2 := (2, 3, 3, 4, 4)
return seq:value-union( $s1, $s2 )

(: vim:set et sw=2 ts=2: :)
