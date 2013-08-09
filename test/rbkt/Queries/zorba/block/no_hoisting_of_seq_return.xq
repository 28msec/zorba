declare namespace ann = "http://zorba.io/annotations";

declare %ann:sequential function local:foo() 
{
  1
};

for $x in (1,2,3)
return
  local:foo()

