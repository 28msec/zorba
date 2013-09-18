import module namespace node = "http://zorba.io/modules/node";

let $x :=  <a>
             <b/>
             <b/>
             <b/>
             <b>
               <c/>
               <c/>
               <c/>
               <c/>
             </b>
           </a>
let $y := <y/>
return
  (
    node:ancestor-of($x/b[1], $x),
    node:ancestor-of($x, $x/b[1]),
    node:descendant-of($x, $x/b[1]),
    node:descendant-of($x/b[1], $x),
    node:following-of($x/b[1], $x/b/c[1]),
    node:following-of($x/b/c[1], $x/b[1]),
    node:preceding-of($x/b/c[1], $x/b[1]),
    node:preceding-of($x/b[1], $x/b/c[1]),
    node:preceding-sibling-of($x/b[2], $x/b[1]),
    node:preceding-sibling-of($x/b[1], $x/b[2]),
    node:following-sibling-of($x/b[1], $x/b[2]),
    node:following-sibling-of($x/b[2], $x/b[1]),
    node:parent-of($x/b[2], $x),
    node:parent-of($x, $x/b[2]),
    node:child-of($x, $x/b[2]),
    node:child-of($x/b[2], $x),
    node:level($x/b[1]),
    node:level($x),
    node:least-common-ancestor($x, $x/b[1]),
    node:least-common-ancestor($x/b[1], $x),
    node:least-common-ancestor($x/b[1], $x/b[1]),
    node:least-common-ancestor($x/b[1], $x/b/c[1]),
    node:least-common-ancestor($x/b[1], $y)
  )
