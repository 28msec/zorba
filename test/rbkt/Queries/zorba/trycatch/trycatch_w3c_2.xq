declare namespace err="http://www.w3.org/2005/xqt-errors";
try {
  fn:error(fn:QName('http://www.w3.org/2005/xqt-errors', 'err:FOER0000'))
}
catch * {
  $err:code, $err:description
}
