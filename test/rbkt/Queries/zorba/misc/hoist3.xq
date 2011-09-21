
declare function local:rec($x) 
{
  for $a in (0 to $x - 1)
  return ($a, local:rec($x - 1))
};

local:rec(3)

(:

R0 --> ()
R1 --> (0)
R2 --> (0, 0 | 1, 0)
R3 --> (0, (0, 0, 1, 0), | 1, (0, 0, 1, 0), | 2, (0, 0, 1, 0))

:)
