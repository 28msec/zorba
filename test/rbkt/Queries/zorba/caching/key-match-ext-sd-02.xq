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

variable $old :=
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
);
variable $old-values := (for $i in (1 to 10) return $old[$i * 2 - 1]);
variable $old-uuids := (for $i in (1 to 10) return $old[$i * 2]);

variable $advance := <x/>;
rename node $advance as "y";

variable $re-evaluated := 
(  
  debug:test-02-sd(()),
  debug:test-02-sd(xs:integer(1)),
  debug:test-02-sd($node),
  debug:test-02-sd($object),
  debug:test-02-sd($array),
  debug:test-02-sd($array-2),
  debug:test-02-sd(xs:long(1)),
  debug:test-02-sd(<a/>),
  debug:test-02-sd({"a" : 1}),
  debug:test-02-sd([1]),
  debug:test-02-sd([2])
);
variable $expected-new-values := (for $i in (1 to 11) return $re-evaluated[$i * 2 - 1]);
variable $expected-new-uuids := (for $i in (1 to 11) return $re-evaluated[$i * 2]);

(
  for $i in (1 to 10)
  return "Called with " || $old-values[$i] || ": NOT CACHED" || "&#10;",
  for $j in (1 to 11)
  return "Called with " || $expected-new-values[$j] || ": " || local:is-cached($expected-new-uuids[$j], $old-uuids) || "&#10;" 
)