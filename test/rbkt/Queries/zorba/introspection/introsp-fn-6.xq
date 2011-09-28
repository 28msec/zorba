
(: There are two signatures for the "substring" function, 
   but sctx:function-names() should return only one QName for it
:)

import module namespace sctx = "http://www.zorba-xquery.com/modules/introspection/sctx";

let $cnt := count(
  for $func in sctx:function-names()
  let $name := local-name-from-QName($func)
  where $name eq "substring"
  return $name
) 
return $cnt eq 1
