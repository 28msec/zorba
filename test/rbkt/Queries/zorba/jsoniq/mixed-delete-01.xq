declare variable $a := (["foo"], ["bar", 1, 2], 1, {"1" : "one"}, <a/>);

delete json $a(1);

$a
