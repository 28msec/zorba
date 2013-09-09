import module namespace node = "http://zorba.io/modules/node";

let $node :=
  <a>
    <b>
      <c/>
    </b>
  </a>
let $new-node := node:copy($node/b)
return ($node/b is $new-node, $new-node/parent::a)
