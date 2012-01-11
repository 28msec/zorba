declare function local:window($seq)
{
  for tumbling window $w in $seq
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

local:window(1 to 10)

