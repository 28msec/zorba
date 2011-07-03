declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare variable $x as xs:integer := 1;

declare %ann:sequential function local:f() 
{
  variable $y as xs:integer := 2;
  $x + $y
};


local:f()

