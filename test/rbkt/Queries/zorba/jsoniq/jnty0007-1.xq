copy $o := { "foo" : "bar" }
modify (
  delete json $o(2)
)
return $o