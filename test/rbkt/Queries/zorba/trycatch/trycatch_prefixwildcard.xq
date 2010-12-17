try {
  fn:error(fn:QName("urn", "foo"), "blub")
} catch *:foo {
  "boom shaka"
}
