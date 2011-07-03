declare namespace ann = "http://www.zorba-xquery.com/annotations";
declare namespace extern="urn:extern";
declare %ann:nondeterministic function extern:nondeterm() external;

declare %ann:nondeterministic function local:func()
{
  let $r := extern:nondeterm( )
  return
    if ($r > 0 and $r < 10) then "Yes" else "No" ,

  extern:nondeterm()
};

local:func()

