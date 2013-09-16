

declare namespace opt = "http://zorba.io/options/optimizer";

declare option opt:enable "for-serialization-only";


declare function local:dummy($x as xs:integer) as xs:integer
{
  $x
};


declare function local:submitMessage($msg)
{   
  local:dummy(2);

  fn:trace(fn:serialize($msg), "  - submitMessage");
};


declare function local:publishResults($results)
{   
  for $rez in $results
  return local:submitMessage(<submission>{ $rez/suite }</submission>)
};


local:publishResults(<rez><suite/></rez>);

local:publishResults(<rez><suite>{ <test/> }</suite></rez>);
