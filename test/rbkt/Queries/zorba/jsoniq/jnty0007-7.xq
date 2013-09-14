copy $a := [ "foo" ]
modify (
  replace value of json $a("foo") with "bar"
)
return $a
