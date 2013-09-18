declare namespace ann = "http://zorba.io/annotations";

declare %ann:sequential function local:foo() 
{
  let $hello := <hello/>
  return insert node <bar/> as last into $hello
};

local:foo()
