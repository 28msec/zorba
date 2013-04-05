
let $values := (3, 3, 5, 6, 7, 7, 7)

return $values[(for $val at $pos in $values where $val eq . return $pos)[2]]

(:
return $values[index-of($values, .)[2]]
:)

