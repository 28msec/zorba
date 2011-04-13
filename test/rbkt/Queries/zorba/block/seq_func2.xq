declare %sequential function local:foo() as xs:boolean 
{
  fn:true()
};

declare %sequential function local:bar() as xs:boolean 
{
local:foo()
};

(:
declare %sequential function local:bar() as xs:boolean 
{
let $x := local:foo()
return $x
};
:)

local:bar()
