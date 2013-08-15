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

(:

declare function local:pns($e)
{
  let $temp3 := treat($e)
  let $parent := $e/parent::*
  let $temp2 := treat($parent)
  let $temp0 := fn:in-scope-prefixes($parent)

  for $prefix in for $prefixE in fn:in-scope-prefixes($e)
                 let $temp1 := fn:namespace-uri-for-prefix($prefixE, $e)
                 for $prefixP in $temp0
                 where $prefixE eq $prefixP and
                       $temp1 ne fn:namespace-uri-for-prefix($prefixP, $temp2)
                 return $prefixE
  return
  ( " ",
    <span class="ns">
    { ( fn:concat("xmlns:", $prefix, '="'),
        <span class="nsUri">{fn:namespace-uri-for-prefix($prefix, $temp3)}</span>,
        '"')
    }</span>
  )
};

:)
