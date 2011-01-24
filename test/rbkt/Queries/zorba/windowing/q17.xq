declare variable $seq := fn:doc("cxml.xml");

<result>{
for sliding window $w in $seq/sequence/* 
  start  $cur previous $prev 
   when day-from-dateTime($cur/@date) ne day-from-dateTime($prev/@date) or empty($prev)
  end $end next $next
   when day-from-dateTime(xs:dateTime($end/@date)) ne
day-from-dateTime(xs:dateTime($next/@date))
return
  <mostValuableCustomer endOfDay="{xs:dateTime($cur/@date)}">{
    let $companies :=   for $x in distinct-values($w/@billTo ) 
                        return <amount company="{$x}">{sum($w[@billTo eq $x]/@total)}</amount>
    let $max := max($companies) 
    for $company in $companies
    where $company eq xs:untypedAtomic($max)
    return $company
  }</mostValuableCustomer>
}</result>
