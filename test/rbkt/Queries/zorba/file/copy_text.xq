import module namespace fct = "http://www.zorba-xquery.com/tests/file_copy_test" at "copy.xqlib";

declare variable $rbktSrcPath as xs:string external;
declare variable $rbktBinPath as xs:string external;

fct:test-copy($rbktSrcPath, $rbktBinPath, "text.txt")
