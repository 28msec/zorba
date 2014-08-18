declare namespace an = "http://zorba.io/annotations";

declare %an:strictlydeterministic %an:exclude-from-cache-key(1, 3) function local:function(
    $a as xs:string,
    $b as xs:string*,
    $c as xs:string
) as object()*
{
    {"v":$a || $b || $c}
};

local:function("1", ("a"), "1"),
local:function("2", ("a"), "2")