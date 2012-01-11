
declare function local:clone-node($source as node())
{
  local:generate-map($source);
};


declare function local:generate-map($source as node()*)
{
  variable $sources := $source//node();

  for $source at $i in $sources
  return trace($source, "source")
};


local:clone-node(<a/>)
