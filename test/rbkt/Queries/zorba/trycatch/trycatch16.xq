declare namespace err = "http://www.w3.org/2005/xqt-errors";
declare namespace zerr = "http://zorba.io/errors";

try {
  1
  div
  0
} catch * {
  $err:line-number,
  $err:column-number,
  $zerr:line-number-end,
  $zerr:column-number-end
}
