import module namespace debug = "http://zorba.io/modules/util-tests";
declare namespace an = "http://zorba.io/annotations";

declare %an:cache %an:compare-with-deep-equal(2) function local:test-07-cache($x as item(), $y as item())
{
  serialize({"x" : $x, "y" : $y}),
  debug:uuid()
};

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
  local:test-07-cache($node, <b/>),
  local:test-07-cache($object, {"b": 2}),
  local:test-07-cache($array, [2]),
  local:test-07-cache(1, 2)
)

let $old-values := (for $i in (1 to 4) return $old[$i * 2 - 1])
let $old-uuids := (for $i in (1 to 4) return $old[$i * 2]) 

let $equal := 
(
  local:test-07-cache($node, <b/>),
  local:test-07-cache($object, {"b": 2}),
  local:test-07-cache($array, [2]),
  local:test-07-cache(1, 2)
)

let $expected-old-values := (for $i in (1 to 4) return $equal[$i * 2 -1])
let $expected-old-uuids := (for $i in (1 to 4) return $equal[$i * 2])

let $re-evaluated := 
(
  local:test-07-cache(<a/>, <b/>),
  local:test-07-cache({"a":1}, {"b": 2}),
  local:test-07-cache([1], [2])
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
