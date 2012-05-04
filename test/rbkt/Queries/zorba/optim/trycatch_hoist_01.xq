

import module namespace reflection = "http://www.zorba-xquery.com/modules/reflection";

import module namespace err = "http://www.w3.org/2005/xqt-errors";

for $x in (1,2,3)
let $code := "($x cast as xs:integer, 1, 2, 3)"
return
  try 
  {
    reflection:eval($code)
  }
  catch err:FORG0001
  {
    $err:code eq $err:FORG0001
  } 
