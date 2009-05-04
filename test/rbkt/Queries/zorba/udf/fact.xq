declare function local:fact ($x as xs:integer) {
  if ($x eq 0) then 1
  else $x * local:fact ($x - 1)
};

local:fact (3)
