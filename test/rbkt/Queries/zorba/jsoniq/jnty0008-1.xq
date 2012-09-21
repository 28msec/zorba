copy $a := [ "foo" ]
modify (
  insert json { "foo" : "bar" } into $a
)
return $a