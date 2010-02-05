declare namespace lib = "lib";

declare function lib:pick($map as node()*, $repl as node()*) as node()*
{
  for $rec in $map/*
  return
    if ( $repl[name() eq name($rec)] )
    then ()
    else $rec
};

lib:pick((<a><b/></a>, <a><c/></a>, <x><x1/><b/><x2/></x>), (<b/>))

