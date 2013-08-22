declare namespace ann = "http://zorba.io/annotations";

declare %ann:nonsequential %ann:sequential function local:foo() 
{
  1
};

local:foo()
