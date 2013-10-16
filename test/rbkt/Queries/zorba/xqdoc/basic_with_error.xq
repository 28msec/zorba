import module namespace xqd = "http://zorba.io/modules/xqdoc";
import schema namespace xqds = "http://www.xqdoc.org/1.0";

declare namespace err = "http://www.w3.org/2005/xqt-errors";

declare variable $local:dir :=
  let $base-uri := fn:static-base-uri()
  let $filename := tokenize($base-uri, "/")[last()]
  return fn:substring(
           $base-uri,
           1,
           fn:string-length($base-uri) - fn:string-length($filename));

try { 
  xqd:xqdoc($local:dir || "gdata_error.xqlib")
} catch *  {
  $err:code, fn:substring($err:description, 1, 62)
}
