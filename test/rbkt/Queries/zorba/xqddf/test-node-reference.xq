import module namespace ref = "http://zorba.io/modules/reference";

declare namespace zerr = "http://zorba.io/modules/zorba-errors";

declare function local:foo($ref as xs:anyURI) {
  ref:dereference($ref) 
};

fn:empty(local:foo(xs:anyURI("sausalito://www.google.com")))
