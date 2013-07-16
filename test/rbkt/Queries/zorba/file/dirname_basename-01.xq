import module namespace file = "http://expath.org/ns/file";

declare function local:do( $path ) {
  fn:concat( file:dir-name( $path ), '|', file:base-name( $path ) )
};

if ( file:directory-separator() eq "\" )
then
 let $path := "C:\a\b"
 return local:do( $path ) eq "C:\a|b"
else
 let $path := "/a/b"
 return local:do( $path ) eq "/a|b"

(: vim:set et sw=2 ts=2: :)
