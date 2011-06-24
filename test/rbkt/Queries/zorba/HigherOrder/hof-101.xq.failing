xquery version "3.0";

declare function local:Y($f) {
function($a) { $f(local:Y($f), $a) }
};

local:Y(function($f, $a) { $a, $f($a + 1) })(1)
