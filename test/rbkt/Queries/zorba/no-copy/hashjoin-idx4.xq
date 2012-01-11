declare namespace opt = "http://www.zorba-xquery.com/options/optimizer";

declare option opt:enable "for-serialization-only";

declare function local:pns($e)
{
  let $parent := $e/parent::*
  let $prefixes :=
    for $prefixE in fn:in-scope-prefixes($e)
    for $prefixP in fn:in-scope-prefixes($parent)
    where $prefixE eq $prefixP and
          fn:namespace-uri-for-prefix($prefixE, $e) ne
          fn:namespace-uri-for-prefix($prefixP, $parent)
    return $prefixE
  for $prefix in $prefixes
  return
  (: <span class="ns">xmlns="<span class="nsUri">http://ex</span>"</span> :)
  ( " ",
    <span class="ns">
    { ( fn:concat("xmlns:",$prefix, '="'),
        <span class="nsUri">{fn:namespace-uri-for-prefix($prefix, $e)}</span>,
        '"')
    }</span>
  )
};

local:pns(
<r1 xmlns:a="a1" xmlns:b="b1">
<r2 xmlns:a="a2" xmlns:c="c1" />
<r2 xmlns:b="b2" xmlns:c="c2" />
</r1>/r2[1]
)

