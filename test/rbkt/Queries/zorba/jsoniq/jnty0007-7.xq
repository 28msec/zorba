copy $a := [ "foo" ]
modify (
  replace json value of $a("foo") with "bar"
)
return $a