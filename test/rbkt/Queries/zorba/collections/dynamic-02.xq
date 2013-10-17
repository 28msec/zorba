import module namespace dml = "http://zorba.io/modules/store/dynamic/collections/dml";
import module namespace ddl = "http://zorba.io/modules/store/dynamic/collections/ddl";

declare variable $coll := xs:QName("dml:coll1");

declare variable $content := ();

declare function local:check($nodes)
{
  for $i at $y in $content
  return
    if ($i is $nodes[$y])
    then ()
    else fn:error()
};

ddl:create($coll);

$content := dml:apply-insert-first($coll, for $i  in 1 to 10 return <b>{$i}</b>);
local:check(dml:collection($coll)[position() <= 10]);

$content := dml:apply-insert-last($coll, for $i  in 1 to 10 return <c>{$i}</c>);
local:check(dml:collection($coll)[position() > last() - 10]);

$content := dml:apply-insert-before($coll, dml:collection($coll)[2], for $i  in 1 to 10 return <d>{$i}</d>);
local:check($coll)[1 < position() and position() <= 11];

$content := dml:apply-insert-after($coll, dml:collection($coll)[2], for $i  in 1 to 10 return <e>{$i}</e>);
local:check($coll)[2 < position() and position() <= 12];

dml:collection($coll)
