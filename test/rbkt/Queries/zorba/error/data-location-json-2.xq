import module namespace file = "http://expath.org/ns/file";
import module namespace json = "http://www.zorba-xquery.com/modules/converters/json";
declare namespace zerr = "http://zorba.io/modules/zorba-errors";

let $file := "$RBKT_SRC_DIR/Queries/zorba/error/data-location.json"
let $json := file:read-text( $file )
return
  try {
    json:parse( $json )
  }
  catch * {
    file:base-name( $zerr:data-uri ),
    $zerr:data-line-number,
    $zerr:data-column-number
  }

(: vim:set et sw=2 ts=2: :)
