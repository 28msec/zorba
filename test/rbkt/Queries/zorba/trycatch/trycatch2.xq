(: test to check if an error is rethrown if non of the catch clauses matches :)
declare namespace err="http://www.w3.org/2005/xqt-errors";
let $x := 'a'
return
try {
    $x cast as xs:integer 
} catch err:XPST0051 { 
  "Cast failed: item does not have a known, atomic type"
} catch err:XPST0050 {
    "Ha! It worked"
}
