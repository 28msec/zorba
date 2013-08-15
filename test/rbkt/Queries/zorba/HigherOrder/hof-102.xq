declare namespace o = "http://zorba.io/options/features";
declare namespace err = "http://www.w3.org/2005/xqt-errors";

try { function () { fn:error() } () } catch err:FOER0000 { 0 }
