import module namespace file = "http://expath.org/ns/file";

declare function local:do( $path ) {
  fn:concat( file:dir-name( $path ), '|', file:base-name( $path ) )
};

let $path := fn:concat("a", file:directory-separator(), "b")
return local:do( $path ) eq "a|b"

(: vim:set et sw=2 ts=2: :)
