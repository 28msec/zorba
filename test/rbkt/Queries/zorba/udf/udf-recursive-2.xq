import schema namespace d = "http://foo.com/schemas/schema" at "schema.xsd";

declare function local:recursion($param as element(*, d:Content)?) as xs:boolean
{
  if ($param)
  then local:recursion(())
  else false()
};

local:recursion(validate { <d:Content id="foo"/> })
