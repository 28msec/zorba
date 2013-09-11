import module namespace map = "http://zorba.io/modules/unordered-maps";

declare namespace ann = "http://zorba.io/annotations";

declare variable $local:processed-internal-links as xs:string := "processed-internal-links";


declare variable $result := ();


declare %ann:sequential function local:f1($n as xs:string)
{
  map:insert($local:processed-internal-links, $n, $n);

  $result := ($result, $n);

  for $x in ("1", "2", "3")
  return
    if(fn:empty(map:get($local:processed-internal-links, $x))) then
      local:f1($x)
    else
      ()
};


map:create($local:processed-internal-links, xs:QName("xs:string"));

local:f1("0");

$result

