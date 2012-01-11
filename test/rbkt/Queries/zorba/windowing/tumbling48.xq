declare variable $local:foo as xs:integer* := 1 to 5;

declare function local:window()
{
  for tumbling window $w1 in $local:foo
  start $s when true()
  end $e when $e - $s eq 3
  for tumbling window $w2 in $w1
  start $s when true()
  end $e when true()
  return
  <window>{
    fn:distinct-values($w1[.=$w2])
  }</window>
};

local:window()

