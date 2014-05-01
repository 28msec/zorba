import module namespace dctx = "http://zorba.io/modules/dctx";

variable $x := dctx:snapshot-id();
variable $i := 0;
while($i < 3)
{
    $i := $i + 1;
};
$x, dctx:snapshot-id()