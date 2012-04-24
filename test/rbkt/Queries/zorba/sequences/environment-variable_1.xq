let $a :=
  for $var in fn:available-environment-variables()
  return fn:environment-variable($var)
return exists($a)                                             