try {
  fn:error(fn:QName('http://www.w3.org/2005/xqt-errors', 'err:FOER0000')) 
} catch (err:FOER0000) { 
  "caught thrown error"
} 
