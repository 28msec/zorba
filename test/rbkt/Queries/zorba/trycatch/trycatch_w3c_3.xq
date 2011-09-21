declare namespace err="http://www.w3.org/2005/xqt-errors";
declare function local:thrice($x as xs:integer) as xs:integer
{
    3*$x
};

local:thrice(try { "oops" } catch * { 3 } )
