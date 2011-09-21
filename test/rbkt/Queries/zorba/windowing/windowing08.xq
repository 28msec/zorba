for tumbling window $w in (2, 4, 6, 8, 10, 12, 14)
    start next $n when $n eq 6
    end previous $p when $p eq 8
return <r>{($n, $p)}<w>{$w}</w></r>
