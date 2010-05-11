
declare function local:last-benchmark()
{
  "blub"
};


declare function local:benchmark($last-benchmark)
{
  $last-benchmark
};


block 
{
declare $last-benchmark;

let $l := local:last-benchmark()
return
  if (not($l))
  then set $last-benchmark := try { fn:error(xs:QName("local:blub")) } catch * { () }
  else ();

local:benchmark($last-benchmark);
}
