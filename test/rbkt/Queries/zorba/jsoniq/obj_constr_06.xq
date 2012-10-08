declare namespace err = "http://www.w3.org/2005/xqt-errors";
declare namespace jerr = "http://jsoniq.org/errors";

try { { { 1 : 1 } : 1 } } catch jerr:JNTY0004 { $err:description }
