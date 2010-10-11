import module namespace mod1 = "http://www.zorba-xquery.com/mod1" at "file:///${CMAKE_CURRENT_BINARY_DIR}/ext_in_opt.xqlib";

declare variable $local:foo external;

mod1:default()
