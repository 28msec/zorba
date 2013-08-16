(: The purpose of the query is to the parsing of annotations
   literals. The value will be ignored :)

declare namespace ann = "http://zorba.io/annotations";

declare %ann:sequential(123) function local:func() {   1 };

local:func()
