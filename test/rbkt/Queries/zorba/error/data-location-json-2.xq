import module namespace file = "http://expath.org/ns/file";
import module namespace jn = "http://jsoniq.org/functions";
declare namespace zerr = "http://zorba.io/modules/zorba-errors";

let $file := "$RBKT_SRC_DIR/Queries/zorba/error/data-location.json"
let $json := file:read-text( $file )
return
  try {
    jn:parse-json( $json )
  }
  catch * {
    file:base-name( $zerr:data-uri ),
    $zerr:data-line-number,
    $zerr:data-column-number
  }

(: vim:set et sw=2 ts=2: :)
