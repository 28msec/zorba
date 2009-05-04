let $d1 := xs:yearMonthDuration("P20Y")
let $d2 := xs:yearMonthDuration("P10M")
let $seq1 := ($d1, $d2)
let $seq3 := (3, 4, 5)
let $nan := xs:double("NaN")
return
  (fn:sum(($d1, $d2)), fn:sum($seq1[. < xs:yearMonthDuration('P3M')], xs:yearMonthDuration('P0M')), fn:sum((),()), fn:sum((1 to 100)[.<0], 0), fn:sum(($seq3, $nan)))
