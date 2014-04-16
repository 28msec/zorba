import module namespace dctx = "http://zorba.io/modules/dctx";

variable $a := dctx:snapshot-id();
variable $x1 := 0;
$a := ($a, dctx:snapshot-id());
variable $x2;
$a := ($a, dctx:snapshot-id());
$x1:=1;
$a := ($a, dctx:snapshot-id());
$x2:=1;
($a, dctx:snapshot-id())