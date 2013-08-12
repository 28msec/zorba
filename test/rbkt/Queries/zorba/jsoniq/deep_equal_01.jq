let $o1 := { foo : 42, bar : 23 }
let $o2 := { foo : 42 }
let $o3 := { foo : { bar : [ 1 to 10 ] }, blub : null }
let $o4 := { blub : null, foo : { bar : [ 1 to 10 ] } }
let $o5 := { }
let $a1 := [ 1, 2, $o3 ]
let $a2 := [ 1, 2, $o4 ]
let $a3 := [ $o3, 1, 2 ]
let $a4 := [ 1, 2, $o4, 3 ]
return
  (
    deep-equal($o1, $o2), 
    deep-equal($o3, $o4),
    deep-equal($o5, $o5),
    deep-equal($a1, $a2),
    deep-equal($a1, $a3),
    deep-equal($a2, $a4)
  )
