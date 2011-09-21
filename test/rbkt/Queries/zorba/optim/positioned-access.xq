declare variable $n1 := (2, 3, 6);
declare variable $n2 := (2, 3);

declare function local:f($x as xs:integer*) 
{
  $x[$x[$x[1]]]
};

local:f($n1),
local:f($n2)


