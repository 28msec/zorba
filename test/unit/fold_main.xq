import module namespace mod1 = "http://www.zorba-xquery.com/mod1" at "${CMAKE_CURRENT_BINARY_DIR}/fold_mod1.xq";

declare variable $local:foo external;

eval { concat("mod1:", $local:foo, "()") }
