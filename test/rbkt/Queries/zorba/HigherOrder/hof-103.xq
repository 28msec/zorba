declare namespace o = "http://zorba.io/options/features";
declare namespace err = "http://www.w3.org/2005/xqt-errors";

try { function() { 1 div 0 } () } catch err:FOAR0001 { 0 }
