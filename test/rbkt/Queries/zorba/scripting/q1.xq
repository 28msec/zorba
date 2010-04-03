declare variable $sequence := (65 to 90);
declare variable $var := 1;

declare sequential function local:foo()
{
set $var := $var + 1;
$var;
};


declare sequential function local:bar()
{
for $i in (1 to 10)
return
let $rand := local:foo()
return $sequence[$rand]
};

local:bar()
