declare function local:rec($x) 
{
  for $y in (1 to 2)
  return
    if($x)
    then
      ($x, local:rec($x - 1))
    else
      0
};


local:rec(2)

(:

R0 --> 0, 0
R1 --> 1, 0, 0 | 1, 0, 0
R2 --> 2, 1, 0, 0, 1, 0, 0 | 2, 1, 0, 0, 1, 0, 0

:)
