xquery version "3.0";

declare namespace o = "http://www.zorba-xquery.com/options/features";
declare option o:enable "hof";

declare function local:Y($f) {
function($a) { $f(local:Y($f), $a) }
};

local:Y(function($f, $a) { $a, $f($a + 1) })(1)
