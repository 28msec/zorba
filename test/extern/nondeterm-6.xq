declare namespace extern = "urn:extern";
declare nondeterministic function extern:nondeterm() external;

declare function local:func()
{
  for $i in (1 to 5)
  return extern:nondeterm()
};

declare function local:func2()
{
  for $i in (1 to 2)
  return local:func()
};

declare function local:func3()
{
  local:func2()
};

local:func3()
