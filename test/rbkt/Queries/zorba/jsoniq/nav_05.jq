declare variable $o1 := { "array" : [1, {"foo" : 3} , 4] };
declare variable $o2 := { "array" : [10, {"foo" : 30}, 40] };

"array" ! ($o1, $o2).$$[[2]].foo