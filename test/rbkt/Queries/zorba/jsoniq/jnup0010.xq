copy $o := { "foo" : "bar" }
modify (
  rename json $o("foo") as "bar",
  rename json $o("foo") as "bar2"
)
return $o