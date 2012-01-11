declare variable $local:foo as xs:integer* := 1 to 10;


declare function local:window()
{
  for tumbling window $w in $local:foo
  start $s when true()
  end $e when $e - $s eq 3
  return
  <window>{
    if ($w instance of xs:integer)
    then
      $w
    else
      $s
  }</window>
};

local:window()

