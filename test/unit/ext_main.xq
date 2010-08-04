import module namespace ext = "http://www.zorba-xquery.com/m" at "${CMAKE_CURRENT_BINARY_DIR}/ext_mod.xq";

declare variable $local:foo external;

eval { concat("ext:", $local:foo, "()") }
