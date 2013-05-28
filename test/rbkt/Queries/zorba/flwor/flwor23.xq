
let $foo := (
  { "foo" : "bar" },
  { "foo" : "bar" },
  { "foo" : "bar" },
  { "foo" : "bar" },
  { "foo" : "bar" },
  { "foo" : "bar" }
)
return $foo[position() lt 4 and .("id") eq 3]
