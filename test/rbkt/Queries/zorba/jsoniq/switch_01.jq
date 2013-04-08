let $o := { "foo" : "bar" }
select
  switch ($o.foo)
    case "bar" select 42
    case "foo" select 23
    case { "foo" : "bar" } select $o
    default select 2342
