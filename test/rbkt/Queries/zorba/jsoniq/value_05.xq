let $a := <a foo="bar"/>
let $b := { "bar" : 42 }
return $b($a/@foo)
