(: test to check if try catch works if no error is thrown :)
declare namespace err="http://www.w3.org/2005/xqt-errors";
let $x := 1 to 100
return
try {
  let $y := $x
  return $y
} catch err:XPST0051 { 
  "Cast failed: item does not have a known, atomic type"
} catch err:XPST0050 {
    "Ha! It worked"
}
