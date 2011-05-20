let $x := 
<a1>
 <a2 attr1="1"/>
 <a3 attr1="1">
  <a4 attr1="1">
   <a5 attr1="1"/>
  </a4>
 </a3>
 <a6 attr1="1"/>
</a1>
return
fn:innermost($x//node()[@attr1="1"])