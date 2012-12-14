copy $o := { "foo" : "bar" }
modify (
  rename json $o(1) as "bar"
)
return $o