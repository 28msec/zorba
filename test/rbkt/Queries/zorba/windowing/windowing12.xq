declare function local:window() 
{
 let $x := 1 to 1000
 for tumbling window $w in $x
 start at $s when fn:true()
 end at $e when $e - $s eq 51
 return <window>{ $w }</window>
};

local:window()
