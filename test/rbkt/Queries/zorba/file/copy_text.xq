import module namespace fct = "http://www.zorba-xquery.com/tests/file_copy_test" at "copy.xqlib";

declare variable $rbktPath as xs:string external;

fct:test-copy($rbktPath, "text.txt")
