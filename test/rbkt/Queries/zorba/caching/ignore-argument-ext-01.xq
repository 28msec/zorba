import module namespace debug = "http://zorba.io/modules/util-tests";

{
  "cache":
  [
    debug:test-06-cache(1,1),
    debug:test-06-cache(1,2),
    debug:test-06-cache(1,3),
    debug:test-06-cache(2,1),
    debug:test-06-cache(2,2),
    debug:test-06-cache(2,3)
  ],
  "sd":
  [
    debug:test-06-cache(1,1),
    debug:test-06-cache(1,2),
    debug:test-06-cache(1,3),
    debug:test-06-cache(2,1),
    debug:test-06-cache(2,2),
    debug:test-06-cache(2,3)
  ]
}