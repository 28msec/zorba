let $x := 'a'
try {
    $x cast as integer 
} catch (err:XPST0051) { 
  "Cast failed: item does not have a known, atomic type"
}
