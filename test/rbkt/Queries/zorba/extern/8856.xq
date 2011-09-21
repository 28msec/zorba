let $seq:=(1,7,4,9,23,5)
let $p:=count($seq)
for $a in(1 to $p)
where $seq[$a]>$seq[$a -1]
let $er:=$seq[$a]

return $er