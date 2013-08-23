copy $o := { "foo" : 1, "bar" : 2 }
modify (
  delete json $o({"foo" : "bar"})
)
return $o
