
declare function local:crash() as element()*
{
  for $id in (1,2)
  return element {"a:a"}{}
};

local:crash()
