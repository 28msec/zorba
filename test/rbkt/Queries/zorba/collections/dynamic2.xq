import module namespace dyn = "http://www.zorba-xquery.com/modules/store/collections";

declare variable $coll := xs:QName("dyn:coll1");

declare variable $content := ();

declare function local:check($nodes)
{
  for $i at $y in $content
  return
    if ($i is $nodes[$y])
    then ()
    else fn:error()
};

dyn:create-collection($coll);

$content := dyn:apply-insert-nodes-first($coll, for $i  in 1 to 10 return <b>{$i}</b>);
local:check(dyn:collection($coll)[position() <= 10]);

$content := dyn:apply-insert-nodes-last($coll, for $i  in 1 to 10 return <c>{$i}</c>);
local:check(dyn:collection($coll)[position() > last() - 10]);

$content := dyn:apply-insert-nodes-before($coll, dyn:collection($coll)[2], for $i  in 1 to 10 return <d>{$i}</d>);
local:check($coll)[1 < position() and position() <= 11];

$content := dyn:apply-insert-nodes-after($coll, dyn:collection($coll)[2], for $i  in 1 to 10 return <e>{$i}</e>);
local:check($coll)[2 < position() and position() <= 12];

dyn:collection($coll)
