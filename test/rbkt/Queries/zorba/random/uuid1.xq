import module namespace r = "http://zorba.io/modules/random";

(: all uuids are distinct? :)
let $seq := for $i in 1 to 10 return r:uuid()
return count($seq) eq count(distinct-values($seq))
