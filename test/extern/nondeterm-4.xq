declare namespace extern="urn:extern";
declare %nondeterministic function extern:nondeterm() external;

declare function local:func()
{
  let $r := extern:nondeterm( )
  return
    if ($r > 0 and $r < 10) then "Yes" else "No" ,

  extern:nondeterm()
};

local:func()

