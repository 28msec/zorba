declare namespace o = "http://www.zorba-xquery.com/options/features";
declare namespace err = "http://www.w3.org/2005/xqt-errors";
declare option o:enable "hof";

try { function () { fn:error() } () } catch err:FOER0000 { 0 }
