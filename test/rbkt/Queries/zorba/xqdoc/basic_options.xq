import module namespace xqd = "http://zorba.io/modules/xqdoc";
import schema namespace xqds = "http://www.xqdoc.org/1.0";

declare namespace ann = "http://zorba.io/annotations";
declare namespace opt = "http://zorba.io/modules/xqdoc-options"; 

declare variable $local:dir :=
  let $base-uri := fn:static-base-uri()
  let $filename := tokenize($base-uri, "/")[last()]
  return fn:substring(
           $base-uri,
           1,
           fn:string-length($base-uri) - fn:string-length($filename));

declare %ann:sequential function local:remove-date($xqdoc)
{
  let $date := $xqdoc//xqds:date[1]
  return
	replace value of node $date with "";
  exit returning $xqdoc;
};

let $xqdoc as schema-element(xqds:xqdoc) := 
  validate lax {
    xqd:xqdoc(
      $local:dir || "gdata.xqlib",
      <opt:enable>
        <opt:functions>true</opt:functions>
        <opt:indexes>false</opt:indexes>
      </opt:enable>)
  }
return
  local:remove-date($xqdoc)
