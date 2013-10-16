import module namespace xqd = "http://zorba.io/modules/xqdoc";

declare variable $local:dir :=
  let $base-uri := fn:static-base-uri()
  let $filename := tokenize($base-uri, "/")[last()]
  return fn:substring(
           $base-uri,
           1,
           fn:string-length($base-uri) - fn:string-length($filename));

let $xqdoc := xqd:xqdoc($local:dir || "indentation.xq")
return {
  replace value of node $xqdoc//*:date[1] with "";
  $xqdoc
}
