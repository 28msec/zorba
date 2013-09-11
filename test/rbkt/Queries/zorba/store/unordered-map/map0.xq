import module namespace map = "http://zorba.io/modules/unordered-maps";


{
  map:create("first", "integer");

  (
    for $i in 1 to 1000
    return map:insert("first", $i, concat("value", $i))
  );

  count(map:keys("first")) = map:size("first")
}
