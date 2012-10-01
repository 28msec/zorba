copy $o := { "foo" : "bar" }
modify (
  insert json { "foo" : "bar2" } into $o
)
return $o