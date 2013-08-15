import module namespace map = "http://www.zorba-xquery.com/modules/store/data-structures/unordered-map";

declare namespace ann = "http://zorba.io/annotations";

declare %ann:nonsequential function local:foo() 
{
  map:create(xs:QName("local:mymap"), xs:QName("xs:integer"));
};

local:foo()
