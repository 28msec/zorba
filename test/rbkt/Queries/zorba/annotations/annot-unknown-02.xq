declare namespace unknown = "unknown-annotation";
declare namespace zwarn = "http://www.zorba-xquery.com/warnings";
declare option zwarn:ZWST0002 "error";

declare %unknown:test variable $var := 3;

$var
