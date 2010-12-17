declare namespace urn = "http://www.zorba-xquery.com";

try {
  fn:error(fn:QName("http://www.zorba-xquery.com", "foo"), "blub")
} catch urn:* {
  "boom shaka"
}
