(: test to check if try catch works if no error is thrown :)
declare namespace err="http://www.w3.org/2005/xqt-errors";
let $x := 'a'
return
try {
  $x cast as xs:integer
} catch err:XPST0051 { 
  "Cast failed: item does not have a known, atomic type"
} catch err:XPST0052 | err:FORG0001 {
    "Ha! It worked"
}
