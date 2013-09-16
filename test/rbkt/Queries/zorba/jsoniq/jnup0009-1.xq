copy $o := { "foo" : "bar" }
modify (
  replace value of json $o("foo") with "bar",
  replace value of json $o("foo") with "bar2"
)
return $o
