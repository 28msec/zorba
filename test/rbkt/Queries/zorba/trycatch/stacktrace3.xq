declare namespace zerr = "http://www.zorba-xquery.com/errors";

try
{
  1 div 0
} catch * {
  $zerr:stack-trace
}
