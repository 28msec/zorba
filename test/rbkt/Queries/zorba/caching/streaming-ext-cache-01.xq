declare namespace ann = "http://zorba.io/annotations";
import module namespace debug = "http://zorba.io/modules/util-tests";

debug:test-04-cache(debug:non-seeakable-streamable-string(), {debug:non-seeakable-streamable-string() : debug:non-seeakable-streamable-string()}),
debug:test-04-cache(debug:non-seeakable-streamable-string(), {debug:non-seeakable-streamable-string() : debug:non-seeakable-streamable-string()})
