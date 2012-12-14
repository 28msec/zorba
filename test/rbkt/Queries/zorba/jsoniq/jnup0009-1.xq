copy $o := { "foo" : "bar" }
modify (
  replace json value of $o("foo") with "bar",
  replace json value of $o("foo") with "bar2"
)
return $o