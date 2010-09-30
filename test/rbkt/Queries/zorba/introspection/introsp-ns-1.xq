(: 
 :  Check that all default statically known namespaces are present 
 :)

import module namespace sctx = "http://www.zorba-xquery.com/modules/introspection/sctx"; 

let $namespaces := sctx:statically-known-namespaces()
return (
  $namespaces = "fn",
  $namespaces = "xml",
  $namespaces = "xs",
  $namespaces = "xsi",
  $namespaces = "local",
  $namespaces = "sctx"
)
