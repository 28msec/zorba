
declare namespace random = "http://www.zorba-xquery.com/modules/random";

declare %deterministic %deterministic function random:random() as xs:integer external;


random:random()
