declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare %ann:sequential function local:foo() 
{
  let $hello := <hello/>
  return insert node <bar/> as last into $hello
};

local:foo()
