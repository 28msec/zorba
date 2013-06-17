import module namespace file = "http://expath.org/ns/file";
import module namespace sys = "http://www.zorba-xquery.com/modules/system";

declare function local:do( $path ) {
  fn:concat( file:dir-name( $path ), '|', file:base-name( $path ) )
};

if ( sys:property($sys:os-name) eq "Windows" )
then
 let $path := "C:\a"
 return local:do( $path ) eq "C:\|a"
else
 let $path := "/a"
 return local:do( $path ) eq "/|a"

(: vim:set et sw=2 ts=2: :)
