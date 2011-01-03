
declare function local:rec($x) 
{
  if($x)
  then
    for $a in (0 to local:rec($x - 1))
    order by $a
    return (local:rec($x - 1), $a)
  else
    0
};


local:rec(1)


