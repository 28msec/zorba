declare namespace ann = "http://zorba.io/annotations";

declare namespace random = "http://zorba.io/modules/random";

declare %ann:deterministic %ann:nondeterministic function random:random() as xs:integer external;


random:random()
