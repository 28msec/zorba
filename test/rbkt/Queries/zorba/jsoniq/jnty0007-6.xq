copy $o := { "foo" : "bar" }
modify (
  replace value of json $o(1) with "bar"
)
return $o
