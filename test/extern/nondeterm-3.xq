declare namespace extern = "urn:extern";
declare %nondeterministic function extern:nondeterm() external;

declare %nondeterministic function local:func()
{
  for $i in (1 to 5)
  return extern:nondeterm()
};

local:func()
