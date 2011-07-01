declare namespace extern = "urn:extern";
declare %nondeterministic function extern:nondeterm() external;

declare %nondeterministic function local:func()
{
  local:func2()
};

declare %nondeterministic function local:func2()
{
  for $i in (1 to 2)
  return local:func3()
};

declare %nondeterministic function local:func3()
{
  for $i in (1 to 5)
  return extern:nondeterm()
};

local:func()
