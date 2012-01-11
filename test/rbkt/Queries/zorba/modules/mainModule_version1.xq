xquery version "1.0";

(: importing a module with a higher version number should raise an error :)
import module namespace foo = "http://foo.com/" at "libraryModule_version3.xqlib";

foo:bar()
