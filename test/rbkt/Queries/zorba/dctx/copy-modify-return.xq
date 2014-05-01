import module namespace dctx = "http://zorba.io/modules/dctx";
variable $x := <x/>;
variable $y := dctx:snapshot-id();
variable $z := 
  copy $copy := $x
  modify rename node $copy as "y"
  return $copy;
$y, dctx:snapshot-id()