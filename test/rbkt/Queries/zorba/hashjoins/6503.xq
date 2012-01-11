
<results>
  {
    let $s := doc("6503.xml")/states
    for $s1 in $s/state,
        $s2 in $s/state
    let $c1 := count($s1/park)
    let $c2 := count($s2/park)
    where $c1 < $c2
   return 
     if (fn:exists($s/state[name eq $s1/name]))
     then
       <result>      
         <name>{$s/state}</name>
         <count>{count($s/state/park)}</count>
       </result>
      else()
  }
</results> 


