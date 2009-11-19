
<results>
  {
    let $s := doc("6490.xml")/states
    for $s1 in $s/state,
        $s2 in $s/state
    let $c1 := count($s1/park)
    let $c2 := count($s2/park)
    where $c1 < $c2
   return 
      let $n := $s1/name
      for $s3 in $s/state[name eq $n]
      return
    <result>      
      <name>{$s3/name}</name>
      <count>{count($s3/park)}</count>
    </result>      
  }
</results> 


