declare variable $cnt := 1;
declare variable $map := <a><b1/><b2/></a>;
declare variable $repl := <c/>;

while ($cnt <3)
{
  $cnt := $cnt + 1;
  for $rec in $map/*
  return
    if ( $repl[name() eq name($rec)] )
    then ()
    else $rec
}
