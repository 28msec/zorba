declare namespace unknown = "unknown-annotation";
declare namespace zwarn = "http://zorba.io/options/warnings";

(: all warnings are errors :)
declare option zwarn:error "all";
declare option zwarn:enable "ZWST0002";

declare %unknown:test variable $var := 3;

$var
