let $x := <a1><a2/></a1>
let $y := <a2/>
return 
 fn:generate-id($x) eq fn:generate-id($y)