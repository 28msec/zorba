
let $x := <a><b/></a>
return fn:count(<c>{$x, $x, $x}</c>/a)
