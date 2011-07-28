declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare %ann:nonsequential %ann:sequential function local:foo() 
{
  1
};

local:foo()
