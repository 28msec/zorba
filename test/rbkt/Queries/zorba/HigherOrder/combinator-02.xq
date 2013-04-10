(: Y combinator test :)

declare function local:Y($f) {
function($a) { $f(local:Y($f), $a) }
};

local:Y(function($f, $a) { $a, if ($a < 500) then $f($a + 1) else -1 })(1)
