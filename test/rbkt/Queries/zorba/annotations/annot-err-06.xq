
declare namespace random = "http://www.zorba-xquery.com/modules/random";

declare %nondeterministic %nondeterministic function random:random() as xs:integer external;


random:random()
