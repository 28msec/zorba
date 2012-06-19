copy $a := [ "foo" ]
modify (
  insert json [ "foo" ] into $a at position "foo"
)
return $a