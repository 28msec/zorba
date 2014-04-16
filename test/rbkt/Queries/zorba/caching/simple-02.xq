import module namespace debug = "http://zorba.io/modules/caching-tests";

debug:test-01-cache(2),
"
",
debug:test-01-cache(12),
"
",
debug:test-01-cache(2),
"
",
debug:test-01-cache(12),
"
",
debug:test-01-cache(22),
"
",
debug:test-01-cache(22),
"
"
