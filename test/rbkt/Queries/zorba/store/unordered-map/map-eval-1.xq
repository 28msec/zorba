import module namespace map = "http://zorba.io/modules/unordered-maps";
import module namespace reflection = "http://zorba.io/modules/reflection";

map:create("map", xs:QName("xs:string"),{ "persistent": false() });
map:insert("map", "test", 1);
reflection:eval('map:get("map", "test")')
