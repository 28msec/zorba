
<results>
  {
    let $s := doc("6493.xml")/states
    for $s1 in $s/state,
        $s2 in $s/state
    let $c1 := count($s1/park)
    let $c2 := count($s2/park)
    where $c1 < $c2
   return 
      let $n := $s1/name
      return
      if (fn:exists($s/state[name eq $n]))
      then  ()
      else    
       <result>      
         <name>{$s/state/name}</name>
         <count>{count($s/state/park)}</count>
       </result>
  }
</results> 


