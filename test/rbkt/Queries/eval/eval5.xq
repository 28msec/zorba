declare function local:eval($query as xs:string, $someparam as xs:integer) {
  using $x := $someparam, $query := $query
  eval { $query  }
};

for $y in 1 to 10
return 
  local:eval("for $i in 1 to $x where $i < 5 return $i", $y)
