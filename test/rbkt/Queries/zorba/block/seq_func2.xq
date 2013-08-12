declare namespace ann = "http://zorba.io/annotations";

declare %ann:sequential function local:foo() as xs:boolean 
{
  fn:true()
};

declare %ann:sequential function local:bar() as xs:boolean 
{
local:foo()
};

(:
declare %ann:sequential function local:bar() as xs:boolean 
{
let $x := local:foo()
return $x
};
:)

local:bar()
