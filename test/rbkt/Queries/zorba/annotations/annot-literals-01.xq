(: The purpose of the query is to the parsing of annotations
   literals. The value will be ignored :)

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare %ann:sequential("string literal") function local:func()
{
  1
};

local:func()
