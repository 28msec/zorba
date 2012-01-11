import module namespace node = "http://www.zorba-xquery.com/modules/node";

let $x :=  document { 
            <a>
             <c/>
             <b attr1="1" attr2="2"><!-- blub 1--> blub <!-- blub 2 --> <?pi "foo" ?></b>
             <d/>
            </a>
           }
return
  (
    node:ancestor-of($x/a, $x),
    node:ancestor-of($x/a/b/@attr1, $x),
    node:ancestor-of($x/a/b/text(), $x/a/b),
    node:descendant-of($x/a, $x/a/b/@attr1),
    node:following-sibling-of($x/a/b, $x/a/b/@attr1),
    node:following-sibling-of($x/a/b/@attr1, $x/a/b/@attr2), (: following-sibling axes is empty for attribute nodes :)
    node:following-of($x/a/c, $x/a/b/comment()[1]),
    node:child-of($x/a/b, $x/a/b/comment()[1]),
    node:child-of($x/a/b, $x/a/b/text()),
    node:ancestor-of($x/a/b/text(), $x/a),
    node:descendant-of($x/a/b/text(), $x/a),
    node:following-of($x/a/b/text(), $x/a/d),
    node:child-of($x/a/b/text(), $x/a/b),
    node:parent-of($x/a/b/text(), $x/a/b),
    node:preceding-of($x/a/b/text(), $x/a/c),
    node:preceding-of($x/a/b/text(), $x/a/b),
    node:following-sibling-of($x/a/b/text(), $x/a/b/comment()[2]),
    node:following-sibling-of($x/a/b/text(), $x/a/b/processing-instruction()),
    node:following-sibling-of($x/a/b/text(), $x/a/b/comment()[1]),
    node:preceding-sibling-of($x/a/b/text(), $x/a/b/comment()[1]),
    node:preceding-sibling-of($x/a/b/text(), $x/a/b/comment()[2]),
    node:preceding-sibling-of($x/a/b/text(), $x/a/b/processing-instruction()),
    node:level($x/a/b),
    node:level($x/a/b/text()),
    node:least-common-ancestor($x/a/b/text(), $x/a/b),
    node:least-common-ancestor($x/a/b/text(), $x/a),
    node:least-common-ancestor($x/a/b/text(), $x) is $x
  )
