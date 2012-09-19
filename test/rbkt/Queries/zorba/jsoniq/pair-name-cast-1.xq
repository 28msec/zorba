copy $o := { "foo" : "bar" }
modify (
  insert json { 1 : "bar" } into $o
)
return $o