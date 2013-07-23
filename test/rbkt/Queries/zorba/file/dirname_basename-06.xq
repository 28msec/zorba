import module namespace file = "http://expath.org/ns/file";

declare function local:do( $path ) {
  fn:concat( file:dir-name( $path ), '|', file:base-name( $path ) )
};

if ( file:directory-separator() eq "\" )
then
 let $path := "C:\a\\\"
 return local:do( $path ) eq "C:\|a"
else
 let $path := "/a///"
 return local:do( $path ) eq "/|a"

(: vim:set et sw=2 ts=2: :)
