(: test if prefixes declared by schema imports can be used in type constructors :)
import module namespace xqd = "http://zorba.io/modules/xqdoc";

declare namespace ann = "http://zorba.io/annotations";

declare variable $local:dir :=
  let $base-uri := fn:static-base-uri()
  let $filename := tokenize($base-uri, "/")[last()]
  return fn:substring(
           $base-uri,
           1,
           fn:string-length($base-uri) - fn:string-length($filename));

declare %ann:sequential function local:remove-date($xqdoc)
{
  let $date := $xqdoc//*:date[1]
  return
  replace value of node $date with "";
  exit returning $xqdoc;
};

let $xqdoc := xqd:xqdoc($local:dir || "image.xqlib")
return
  local:remove-date($xqdoc)
