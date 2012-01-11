declare variable $local:foo as xs:integer* := 1 to 10;

declare function local:window()
{
  for tumbling window $w in $local:foo
  start $s when false()
  end $e when false()
  return
    <window>{$w}</window>
};

local:window()
