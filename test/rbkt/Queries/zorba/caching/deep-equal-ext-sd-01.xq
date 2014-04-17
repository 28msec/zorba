import module namespace debug = "http://zorba.io/modules/util-tests";
declare namespace an = "http://zorba.io/annotations";

declare function local:is-cached($uuids, $old-uuids)
{
  if ($uuids = $old-uuids)
  then "CACHED"
  else "NOT CACHED"
};

variable $node := <a/>;
variable $object := {"a": 1};
variable $array := [1];

let $old :=
( 
  debug:test-07-cache($node, <b/>),
  debug:test-07-cache($object, {"b": 2}),
  debug:test-07-cache($array, [2]),
  debug:test-07-cache(1, 2)
)

let $old-values := (for $i in (1 to 4) return $old[$i * 2 - 1])
let $old-uuids := (for $i in (1 to 4) return $old[$i * 2]) 

let $equal := 
(
  debug:test-07-cache($node, <b/>),
  debug:test-07-cache($object, {"b": 2}),
  debug:test-07-cache($array, [2]),
  debug:test-07-cache(1, 2)
)

let $expected-old-values := (for $i in (1 to 4) return $equal[$i * 2 -1])
let $expected-old-uuids := (for $i in (1 to 4) return $equal[$i * 2])

let $re-evaluated := 
(
  debug:test-07-cache(<a/>, <b/>),
  debug:test-07-cache({"a":1}, {"b": 2}),
  debug:test-07-cache([1], [2])
)
let $expected-new-values := (for $i in (1 to 3) return $re-evaluated[$i * 2 - 1])
let $expected-new-uuids := (for $i in (1 to 3) return $re-evaluated[$i * 2])
return
(
  for $i in (1 to 4)
  return "Called with " || $old-values[$i] || ": NOT CACHED" || "&#10;",
  for $j in (1 to 4)
  return "Called with " || $expected-old-values[$j] || ": " || local:is-cached($expected-old-uuids[$j], $old-uuids) || "&#10;",
  for $k in (1 to 3)
  return "Called with " || $expected-new-values[$k] || ": " || local:is-cached($expected-new-uuids[$k], $old-uuids) || "&#10;"
)
