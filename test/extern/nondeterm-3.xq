declare namespace ann = "http://www.zorba-xquery.com/annotations";
declare namespace extern = "urn:extern";
declare %ann:nondeterministic function extern:nondeterm() external;

declare %ann:nondeterministic function local:func()
{
  for $i in (1 to 5)
  return extern:nondeterm()
};

local:func()
