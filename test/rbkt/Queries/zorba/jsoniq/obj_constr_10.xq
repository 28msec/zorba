declare namespace err = "http://www.w3.org/2005/xqt-errors";
declare namespace jerr = "http://www.jsoniq.org/errors";

try { { [ 1 to 3] : 1 } } catch jerr:JNTY0004 { $err:description }
