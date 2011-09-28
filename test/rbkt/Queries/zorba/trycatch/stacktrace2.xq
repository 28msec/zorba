declare namespace zerr = "http://www.zorba-xquery.com/errors";
declare namespace err = "http://www.w3.org/xqt-errors";

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
} catch err:FOAR0002
{
  fn:error()
} catch * {
  copy $blub := $zerr:stack-trace
  modify delete node $blub//@name
  return $blub
}
