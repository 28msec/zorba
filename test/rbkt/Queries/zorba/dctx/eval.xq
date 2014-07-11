import module namespace dctx = "http://zorba.io/modules/dctx";
import module namespace reflection = "http://zorba.io/modules/reflection";

rename node <a/> as "b";
variable $out := dctx:snapshot-id();
variable $in := reflection:eval("dctx:snapshot-id()");
rename node <a/> as "b";
variable $out2 := dctx:snapshot-id();
variable $in2 := reflection:eval("dctx:snapshot-id()");

$out, $in, $out2, $in2