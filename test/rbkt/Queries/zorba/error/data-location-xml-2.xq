import module namespace file = "http://expath.org/ns/file";
declare namespace zerr = "http://zorba.io/errors";

let $file := "$RBKT_SRC_DIR/Queries/zorba/error/data-location.xml"
let $xml := file:read-text( $file )
return
  try {
    fn:parse-xml( $xml )
  }
  catch * {
    file:base-name( $zerr:data-uri ),
    $zerr:data-line-number,
    $zerr:data-column-number
  }

(: vim:set et sw=2 ts=2: :)
