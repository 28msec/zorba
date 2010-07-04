let $doc_chemistry := doc("chemistry.xml")/chemistry
let $compoundWeight := 
    for $c in $doc_chemistry/compound
    for $e in $doc_chemistry/elem[($c/elemName = name)]
    let $c_compoundName := $c/compoundName
    group by $c_compoundName
    let $weight := sum(for $i in 1 to count($e/num)
                       return ($e[$i]/num * $c[$i]/cnt) )
    return <result>
           <weight>{data($weight)}</weight>
           <compoundName>{data($c[1]/compoundName)}</compoundName>
           </result>
let $totalWeight := sum($compoundWeight/weight)
return
<result>
<totalWeight>{data($totalWeight)}</totalWeight>
</result>
