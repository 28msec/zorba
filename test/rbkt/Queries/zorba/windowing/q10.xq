declare variable $seq := fn:doc("person_events.xml");

<result>{
  for tumbling window $w in $seq/stream/event[direction eq "in"]
    start  $s when fn:true() 
    end next $e when xs:date( xs:dateTime($s/@time) ) ne xs:date( xs:dateTime($e/@time) ) 
  let $date := xs:date(xs:dateTime($s/@time))
  where not($w[person eq "Barbara"])
  return <alert date="{ $date }">Barbara did not come to work</alert>
}</result>
