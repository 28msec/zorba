for $seq in (
  { "foo" : 1 },
  { "foo" : 42 },
  { "foo" : null },
  { "foo" : () } )
order by $seq.foo
return $seq
