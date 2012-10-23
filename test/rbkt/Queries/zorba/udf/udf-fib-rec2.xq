declare function local:fib($n as xs:integer) as xs:integer
{
  if ($n eq 0) then 0 
  else if ($n eq 1) then 1 
  else local:fib($n - 1) + local:fib($n - 2)
};

local:fib(10)
