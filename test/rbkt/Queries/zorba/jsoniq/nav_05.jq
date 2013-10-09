declare variable $o1 := { "array" : [1, {"foo" : 3} , 4] };
declare variable $o2 := { "array" : [10, {"foo" : 30}, 40] };

let $v := "array" return ($o1, $o2).$v[[2]].foo,
"
",
let $v := 6 return ($o1, $o2)."array"[[$v]]
