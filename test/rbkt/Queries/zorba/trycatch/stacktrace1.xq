declare namespace zerr = "http://zorba.io/modules/zorba-errors";

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
  copy $copy := $zerr:stack-trace
  modify delete node $copy//@name
  return $copy
}
