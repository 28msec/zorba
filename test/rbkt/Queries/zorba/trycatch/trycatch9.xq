(:
 : check if the error module is correct and its variables
 : can be used to catch an error
 :)
import module namespace err = "http://www.w3.org/2005/xqt-errors";

let $x := 'a'
return
  try {
      $x cast as xs:integer 
  } catch err:FORG0001 {
    $err:code eq $err:FORG0001
  }
