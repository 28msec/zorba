copy $o := { "foo" : "bar" }
modify (
  insert json [ "foo" ] into $o at position 1
)
return $o