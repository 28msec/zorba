declare function local:path-to-node-with-pos( $node as node()? )
{
  for $ancestor in $node/ancestor-or-self::*
  let $sibsOfSameName := $ancestor/../*[name() eq name($ancestor)]
  return (name($ancestor), $sibsOfSameName)
};

local:path-to-node-with-pos (<a/>)
