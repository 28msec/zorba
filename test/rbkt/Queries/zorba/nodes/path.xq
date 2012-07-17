declare namespace ns = "some-namespace";

let $doc := document { <ns:doc/> }/*:doc,
    $a := <a><b/><b><c d="e"/></b><ns:e ns:f="g"/></a>,
    $b := $a/b[c],
    $d := $a/b/c/@d,
    $f := $a//@ns:f
return
  ( path($doc), path($b), path($d), path($f) )
