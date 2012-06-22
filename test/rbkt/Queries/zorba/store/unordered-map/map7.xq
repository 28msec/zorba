import module namespace map = "http://www.zorba-xquery.com/modules/store/data-structures/unordered-map";


variable $name := fn:QName("http://www.zorba-xquery.com/map", "first");
variable $xs-integer := fn:QName("http://www.w3.org/2001/XMLSchema", "xs:integer");
variable $xs-string := fn:QName("http://www.w3.org/2001/XMLSchema", "xs:string");

map:create($name, $xs-integer, $xs-string);

for $i in 1 to 6
let $value := concat("value", $i),
    $key1  := if ($i mod 2 ne 0) then $i else (),
    $key2  := if ($i mod 3 ne 0) then concat("key", $i) else ()
return
  map:insert($name, trace($value, "$value"),
                    trace($key1,  "$key1"),
                    trace($key2,  "$key2"));

for $k in trace(map:keys($name), "keys")
let $key1 := data($k/map:attribute[1]/@value),
    $key2 := data($k/map:attribute[2]/@value)
return
  ($key1, $key2)

(:
map:size($name), map:get($name, 3, ())
:)