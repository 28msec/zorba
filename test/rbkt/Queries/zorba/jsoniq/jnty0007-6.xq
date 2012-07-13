copy $o := { "foo" : "bar" }
modify (
  replace json value of $o(1) with "bar"
)
return $o