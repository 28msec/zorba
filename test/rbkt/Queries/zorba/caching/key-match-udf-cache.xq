import module namespace dctx = "http://zorba.io/modules/dctx";
import module namespace random = "http://zorba.io/modules/random";
declare namespace an = "http://zorba.io/annotations";

declare %an:cache %an:nondeterministic function local:test-02-cache($arg)
{
  serialize($arg),
  random:uuid()
};

declare function local:is-cached($uuids, $old-uuids)
{
  if ($uuids = $old-uuids)
  then "CACHED"
  else "NOT CACHED"
};


variable $node := <a/>;
variable $object := {"a" : 1};
variable $array := [1];
variable $array-2 := [2];

let $old :=
( 
  local:test-02-cache(()),
  local:test-02-cache(xs:int(1)),
  local:test-02-cache(xs:integer(1)),
  local:test-02-cache($node),
  local:test-02-cache($object),
  local:test-02-cache($array),
  local:test-02-cache($node),
  local:test-02-cache($object),
  local:test-02-cache($array),
  local:test-02-cache($array-2)
)
let $old-values := (for $i in (1 to 10) return $old[$i * 2 - 1])
let $old-uuids := (for $i in (1 to 10) return $old[$i * 2]) 
let $equal := 
(
  local:test-02-cache(()),
  local:test-02-cache(xs:integer(1)),
  local:test-02-cache($node),
  local:test-02-cache($object),
  local:test-02-cache($array),
  local:test-02-cache($array-2)
)
let $expected-old-values := (for $i in (1 to 6) return $equal[$i * 2 -1])
let $expected-old-uuids := (for $i in (1 to 6) return $equal[$i * 2])
let $re-evaluated := 
(
  local:test-02-cache(xs:long(1)),
  local:test-02-cache(<a/>),
  local:test-02-cache({"a" : 1}),
  local:test-02-cache([1]),
  local:test-02-cache([2])
)
let $expected-new-values := (for $i in (1 to 5) return $re-evaluated[$i * 2 - 1])
let $expected-new-uuids := (for $i in (1 to 5) return $re-evaluated[$i * 2])
return
(
  for $i in (1 to 10)
  return "Called with " || $old-values[$i] || ": NOT CACHED" || "&#10;",
  for $j in (1 to 6)
  return "Called with " || $expected-old-values[$j] || ": " || local:is-cached($expected-old-uuids[$j], $old-uuids) || "&#10;",
  for $k in (1 to 5)
  return "Called with " || $expected-new-values[$k] || ": " || local:is-cached($expected-new-uuids[$k], $old-uuids) || "&#10;"  
)