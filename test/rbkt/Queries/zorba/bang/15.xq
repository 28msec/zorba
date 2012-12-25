let $doc := document { <a><b>1</b><a><b>2</b></a></a>,<a><b>3</b></a> }
return
  $doc // a ! descendant::b / text()
