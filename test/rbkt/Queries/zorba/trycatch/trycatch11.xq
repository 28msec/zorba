declare namespace err="http://www.w3.org/2005/xqt-errors";

try {
  1 div 0
} catch * {
  $err:code, $err:description, $err:value, contains($err:module, "trycatch11.xq"), $err:line-number, $err:column-number
}

