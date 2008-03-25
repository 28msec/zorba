let $x := 'a'
return
try {
    $x cast as xs:integer 
} catch (err:XPST0051) { 
  "Cast failed: item does not have a known, atomic type"
} catch (*, $error) {
    "Ha! It worked ", string($error/fn:errorcode), string($error/fn:description)
}
