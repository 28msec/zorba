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
  map:insert($name, $value, $key1, $key2);

for $k in map:keys($name)
let $key1 := data($k/map:attribute[1]/@value),
    $key2 := data($k/map:attribute[2]/@value)
order by $key1, $key2
return
  ($key1 instance of xs:integer, $key2 instance of xs:string,
   $key1, $key2, map:get($name, $key1, $key2))
