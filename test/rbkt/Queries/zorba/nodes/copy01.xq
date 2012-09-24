import module namespace node = "http://www.zorba-xquery.com/modules/node";

let $node :=
  <a>
    <b>
      <c/>
    </b>
  </a>
let $new-node := node:copy($node/b)
return ($node/b is $new-node, $new-node/parent::a)
