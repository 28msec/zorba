(:
 : check if the zorba error module is correct and its variables
 : can be used to catch an error
 :)
import module namespace zerr = "http://zorba.io/errors";
import module namespace doc = "http://zorba.io/modules/store/documents";

declare namespace err = "http://www.w3.org/2005/xqt-errors";

let $x := 'a'
return
  try {
    doc:document("urn:foo")
  } catch zerr:ZXQD0002 {
    $err:code eq $zerr:ZXQD0002
  }

