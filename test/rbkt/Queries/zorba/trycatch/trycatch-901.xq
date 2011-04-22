(: try/catch is only avialable in XQuery 3.0, raise XPST0003 :)
xquery version "1.0";

declare variable $x := "0";

try {
  $x cast as xs:integer
} catch e {
  0
}
