import module namespace debug = "http://zorba.io/modules/util-tests";

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
  debug:test-02-sd(()),
  debug:test-02-sd(xs:int(1)),
  debug:test-02-sd(xs:integer(1)),
  debug:test-02-sd($node),
  debug:test-02-sd($object),
  debug:test-02-sd($array),
  debug:test-02-sd($node),
  debug:test-02-sd($object),
  debug:test-02-sd($array),
  debug:test-02-sd($array-2)
)
let $old-values := (for $i in (1 to 10) return $old[$i * 2 - 1])
let $old-uuids := (for $i in (1 to 10) return $old[$i * 2]) 
let $equal := 
(
  debug:test-02-sd(()),
  debug:test-02-sd(xs:integer(1)),
  debug:test-02-sd($node),
  debug:test-02-sd($object),
  debug:test-02-sd($array),
  debug:test-02-sd($array-2)
)
let $expected-old-values := (for $i in (1 to 6) return $equal[$i * 2 -1])
let $expected-old-uuids := (for $i in (1 to 6) return $equal[$i * 2])
let $re-evaluated := 
(
  debug:test-02-sd(xs:long(1)),
  debug:test-02-sd(<a/>),
  debug:test-02-sd({"a" : 1}),
  debug:test-02-sd([1]),
  debug:test-02-sd([2])
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