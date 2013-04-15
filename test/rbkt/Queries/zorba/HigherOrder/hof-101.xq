declare namespace an = "http://www.zorba-xquery.com/annotations";

declare %private variable $handlers := ();

declare %an:sequential function local:add($handler)
{
  $handlers := ($handlers, $handler);
};

declare function local:emit($message)
{
  for $h in $handlers
  return $h($message)
};

declare function local:handle($message)
{
  ("Message:", $message)
};

declare %an:sequential function local:test($message)
{
  local:add(local:handle#1);
  local:emit($message)
};

local:test("This is a test.")
