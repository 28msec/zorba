declare namespace err="http://www.w3.org/2005/xqt-errors";
try {
  fn:error(xs:QName("err:err"), "blub")
} catch err:* {
  element { $err:code } {1}
}
