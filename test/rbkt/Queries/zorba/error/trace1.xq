declare function local:foo() as xs:anyAtomicType
{
  fn:trace(3, "foo")
};

local:foo()
