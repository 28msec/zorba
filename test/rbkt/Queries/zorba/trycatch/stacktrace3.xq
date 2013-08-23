declare namespace zerr = "http://zorba.io/errors";

try
{
  1 div 0
} catch * {
  $zerr:stack-trace
}
