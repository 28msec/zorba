declare namespace extern = "urn:extern";
declare %nondeterministic function extern:nondeterm() external;

declare %nondeterministic function local:func()
{
  for $i in (1 to 5)
  return extern:nondeterm()
};

declare %nondeterministic function local:func2()
{
  for $i in (1 to 2)
  return local:func()
};

declare %nondeterministic function local:func3()
{
  local:func2()
};

local:func3()
