try {
  fn:error(xs:QName("err:err"), "blub")
} catch err:* ($e) {
  element { $e } {1}
}
