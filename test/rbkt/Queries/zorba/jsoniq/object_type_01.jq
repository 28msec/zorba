declare function local:foo() as object
{
  { foo : { 42 : "bar" } }.foo
};

local:foo()
