declare namespace zerr = "http://www.zorba-xquery.com/errors";

declare function local:bar()
{
  1 div 0
};

declare function local:foo()
{
  local:bar()
};

try 
{
  local:foo()
} catch * {
  copy $blub := $zerr:stack-trace
  modify delete node $blub//@name
  return $blub
}
