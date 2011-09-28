
import module namespace mod17 = "http://example17.com" at "libraryModule17.xqlib";

declare namespace mod16 = "http://example16.com";

declare variable $mod16:x := 10;


mod17:foo() , $mod16:x

