declare namespace ann = "http://zorba.io/annotations";
import module namespace debug = "http://www.28msec.com/modules/debug";

debug:test-04-cache(debug:non-seeakable-streamable-string(), {debug:non-seeakable-streamable-string() : debug:non-seeakable-streamable-string()}),
debug:test-04-cache(debug:non-seeakable-streamable-string(), {debug:non-seeakable-streamable-string() : debug:non-seeakable-streamable-string()})
