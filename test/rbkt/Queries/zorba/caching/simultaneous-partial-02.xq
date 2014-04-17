import module namespace debug = "http://zorba.io/modules/util-tests";

(
for $i in debug:test-01-cache(22)
where string($i) = 
 string(
  debug:test-01-cache(try {xs:integer($i)} catch * {22})
  [1])
return $i

),
[debug:test-01-cache(22)],
[debug:test-01-cache(484)]