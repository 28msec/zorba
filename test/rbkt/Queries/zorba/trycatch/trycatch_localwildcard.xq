declare namespace urn = "http://www.zorba-xquery.com";
declare namespace err="http://www.w3.org/2005/xqt-errors";

try {
  fn:error(fn:QName("http://www.zorba-xquery.com", "foo"), "blub")
} catch urn:* {
  "boom shaka"
}
