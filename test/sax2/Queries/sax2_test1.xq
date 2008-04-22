<test:Plan xmlns:test='http://test.org/schema'>
  <test:Case name='test1' emptyAttribute='' test:ns_id='auio'>
  </test:Case>
  <!--
    <foo>Bar</foo>
  -->
  <test:text>my name <b>is</b> foo</test:text>
  <foo:bar xmlns:foo="http://foo.org/">
    <foo:bar foo="foo" />
  </foo:bar>
  <!-- This is a comment -->
  <bar:foo xmlns:bar="http://bar.org/">
    hello
  </bar:foo>
</test:Plan>
