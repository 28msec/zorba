import module namespace map = "http://zorba.io/modules/unordered-maps";

declare namespace ann = "http://zorba.io/annotations";

declare %ann:nonsequential function local:foo() 
{
  map:create("mymap", xs:QName("xs:integer"));
};

local:foo()
