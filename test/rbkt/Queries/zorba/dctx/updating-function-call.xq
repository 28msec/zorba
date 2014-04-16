import module namespace dctx = "http://zorba.io/modules/dctx";

declare variable $x := <x/>;
declare updating function local:update()
{
  rename node $x as "y"
};

variable $y := dctx:snapshot-id();
local:update();
$y, dctx:snapshot-id()