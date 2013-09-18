import module namespace map = "http://zorba.io/modules/unordered-maps";

variable $name := "first";
variable $xs-integer := fn:QName("http://www.w3.org/2001/XMLSchema", "xs:integer");
variable $xs-string := fn:QName("http://www.w3.org/2001/XMLSchema", "xs:string");

map:create($name, [$xs-integer, $xs-string]);

for $i in 1 to 6
let $value := concat("value", $i)
let $key1  := $i
let $key2  := concat("key", $i)
return
  map:insert($name, [$key1, $key2], $value);

for $k in trace(map:keys($name), "key")
let $key1 := jn:members($k)[1]
let $key2 := jn:members($k)[2]
order by $key1, $key2
return
  ($key1 instance of xs:integer, $key2 instance of xs:string,
   $key1, $key2, map:get($name, [$key1, $key2]))
