declare namespace ann = "http://www.zorba-xquery.com/annotations";

(:
 : This query tests if it is possible to have a return type in a function that 
 : contains a sequential block.
 :)
declare %ann:sequential function local:test($x as element(person)) as element(person) 
{
  insert node <age>123</age> into $x;
  $x
};

local:test(<person/>)

