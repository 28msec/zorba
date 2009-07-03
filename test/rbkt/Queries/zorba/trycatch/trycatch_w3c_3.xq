declare function local:thrice($x as xs:integer) as xs:integer
{
    3*$x
};

local:thrice(try { "oops" } catch * { 3 } )
