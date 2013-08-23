import module namespace file = "http://expath.org/ns/file";

declare function local:do( $path ) {
  fn:concat( file:dir-name( $path ), '|', file:base-name( $path ) )
};

if ( file:directory-separator() eq "\" )
then
 let $path := "C:\"
 return local:do( $path ) eq "C:\|C:\"
else
 let $path := "/"
 return local:do( $path ) eq "/|/"

(: vim:set et sw=2 ts=2: :)
