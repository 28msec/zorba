import module namespace dctx = "http://zorba.io/modules/dctx";

declare variable $x := 0;
variable $y := dctx:snapshot-id();
$x := 1;
$y, dctx:snapshot-id()