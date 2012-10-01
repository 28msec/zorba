copy $o := {| |}
modify (
  insert json { "foo" : "bar" } into $o,
  insert json { "foo" : "bar2" } into $o
)
return $o