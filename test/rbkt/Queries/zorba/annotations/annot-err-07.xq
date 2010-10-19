
declare namespace random = "http://www.zorba-xquery.com/modules/random";

declare %deterministic %nondeterministic function random:random() as xs:integer external;


random:random()
