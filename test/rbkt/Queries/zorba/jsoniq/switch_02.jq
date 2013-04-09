let $o := { "foo" : "bar" }
select
  typeswitch ($o)
  case object select $o.foo
  case atomic select error()
  default select error()
