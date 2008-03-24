let $x := 'a'
return
try {
    $x cast as xs:integer 
} catch (err:XPST0051) { 
  "Cast failed: item does not have a known, atomic type"
}
