try {
  fn:error(fn:QName("urn", "foo"), "blub")
} catch urn:* {
  "boom shaka"
}
