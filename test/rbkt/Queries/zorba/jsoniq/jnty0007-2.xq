copy $a := [ "foo" ]
modify (
  delete json $a("foo")
)
return $a