declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare %ann:nonsequential function local:foo() 
{
  let $s := fn:max((1,2,3))
  return
    exit returning ("max:", $s);

  "THIS IS THE SECRET"
};

local:foo()

