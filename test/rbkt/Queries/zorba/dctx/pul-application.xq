import module namespace dctx = "http://zorba.io/modules/dctx";
variable $x := <x/>;
variable $y := dctx:snapshot-id();
rename node $x as "y";
$y, dctx:snapshot-id()