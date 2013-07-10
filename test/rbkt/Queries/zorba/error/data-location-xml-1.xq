import module namespace file = "http://expath.org/ns/file";
declare namespace zerr = "http://zorba.io/modules/zorba-errors";

try {
  fn:doc( "data-location.xml" )
}
catch * {
  file:base-name( $zerr:data-uri ),
  $zerr:data-line-number,
  $zerr:data-column-number
}

(: vim:set et sw=2 ts=2: :)
