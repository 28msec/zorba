
declare function local:last-benchmark()
{
  "blub"
};


declare function local:benchmark($last-benchmark)
{
  $last-benchmark
};


{
  variable $last-benchmark;

  let $l := local:last-benchmark()
  return
    if (not($l))
    then $last-benchmark := try { fn:error(xs:QName("local:blub")) } catch * { () };
    else ();

  local:benchmark($last-benchmark);
}
