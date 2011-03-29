import module namespace ref = "http://www.zorba-xquery.com/modules/node-reference";

declare function local:foo($ref as xs:anyURI) {
  ref:node-by-reference($ref) 
};

try {
  local:foo(xs:anyURI("sausalito://www.google.com"))
} catch zerr:API0028 {
  true()
}
