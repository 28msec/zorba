declare namespace ann = "http://www.zorba-xquery.com/annotations";
declare namespace extern = "urn:extern";
declare %ann:nondeterministic function extern:nondeterm() external;

declare %ann:nondeterministic function local:func()
{
  for $i in (1 to 5)
  return extern:nondeterm()
};

declare %ann:nondeterministic function local:func2()
{
  for $i in (1 to 2)
  return local:func()
};

declare %ann:nondeterministic function local:func3()
{
  local:func2()
};

local:func3()
