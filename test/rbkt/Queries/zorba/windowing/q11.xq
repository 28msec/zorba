declare variable $seq := fn:doc("person_events.xml");

<results>{
  for tumbling window $w in $seq/stream/event[direction eq "in"]
    start when true()
    only end next $x when  $x/person eq "Clara"
  return 
    <result time="{ $x/@time }">{
      distinct-values(for $y in $w 
        where (xs:dateTime($y/@time) + xs:dayTimeDuration("PT15M") ) ge xs:dateTime($x/@time)
        return $y/person)
    }</result>
}</results>
