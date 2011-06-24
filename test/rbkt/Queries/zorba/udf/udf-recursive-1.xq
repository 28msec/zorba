(: Two functions that invoke each other :)

declare function local:get-request-id1($p as xs:integer) as xs:string
{
  for $i in (1 to 3)
  return local:get-request-id2(4)
};

declare function local:get-request-id2($p as xs:integer) as xs:string
{
  local:get-request-id1(4)
};

local:get-request-id1(1)
