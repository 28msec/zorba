xquery version "3.0";
(: Higher Order Functions :)
(: inline function literal, imported user-defined function :)
(: Author - Michael Kay, Saxonica :)

import module namespace m="http://example.com/hof-003" at "hof-003.lib";

declare namespace o = "http://www.zorba-xquery.com/options/features";
declare option o:enable "hof";

let $f := m:f#1 return $f(17)
