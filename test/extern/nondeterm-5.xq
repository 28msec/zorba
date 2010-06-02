declare namespace extern = "urn:extern";
declare nondeterministic function extern:nondeterm() external;

declare function local:func()
{
  for $i in (1 to 5)
  return extern:nondeterm()
};

declare function local:func2()
{
  local:func()
};

local:func2()
