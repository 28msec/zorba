<plan>
  <test:Case xmlns:test='http://test.org/schema' name='test1' emptyAttribute='' test:ns_id='auio'>
  </test:Case><!-- this is a comment -->
  <test:text xmlns:test='http://test.org/schema2'>my name <b>is</b> foo></test:text>
  <text>this is some more text</text>
  <pre:foo xmlns:pre='http://test.org/pre1'>
     <pre:boo1/>
     <pre:boo2/>
     <pre:boo3> <goo1/> <goo2 xmlns:gg='http://test.org/schema3'/> </pre:boo3>
     <pre:boo4>
       <pre:goo3 xmlns:pre='http://test.org/pre2'/>
     </pre:boo4>
  </pre:foo>
</plan>
