import module namespace size = "http://www.zorba-xquery.com/modules/item";

string-join(
  (
    concat("string foo: ", size:size("foo")),
    concat("integer 3: ", size:size(3))
  ), "
")
