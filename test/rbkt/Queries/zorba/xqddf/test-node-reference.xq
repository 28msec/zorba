import module namespace ref = "http://www.zorba-xquery.com/modules/node-reference";

declare namespace zerr = "http://zorba.io/modules/zorba-errors";

declare function local:foo($ref as xs:anyURI) {
  ref:node-by-reference($ref) 
};

try {
  local:foo(xs:anyURI("sausalito://www.google.com"))
} catch zerr:ZAPI0028 {
  true()
}
