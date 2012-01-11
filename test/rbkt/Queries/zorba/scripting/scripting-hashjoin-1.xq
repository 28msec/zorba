declare variable $cnt := 1;
declare variable $map := <a><b1/><b2/></a>;
declare variable $repl := <c/>;
declare variable $result as node()* := ();

while ($cnt <3)
{
  $cnt := $cnt + 1;

  $result := ($result 
              ,
              for $rec in $map/*
              return
              if ( $repl[name() eq name($rec)] )
              then ()
              else $rec);
}

$result
