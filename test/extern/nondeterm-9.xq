declare namespace ann = "http://www.zorba-xquery.com/annotations";
declare namespace extern = "urn:extern";
declare %ann:nondeterministic function extern:nondeterm() external;

declare %ann:nondeterministic function local:func()
{
  local:func2()
};

declare %ann:nondeterministic function local:func2()
{
  for $i in (1 to 2)
  return local:func3()
};

declare %ann:nondeterministic function local:func3()
{
  for $i in (1 to 5)
  return extern:nondeterm()
};

local:func()
