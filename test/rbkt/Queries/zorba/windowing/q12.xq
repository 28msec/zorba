declare variable $seq := fn:doc("person_events.xml");

<result>
{
  for tumbling window $w in $seq/stream/event[direction eq "in"] 
               start $x when $x/person = ("Barbara", "Anton")
               end next $y when xs:dateTime($y/@time) - xs:dateTime($x/@time) gt xs:dayTimeDuration("PT30M")
  where $w[person eq "Anton"] and $w[person eq "Barbara"]
  return 
    <alert date="{ xs:dateTime($y/@time) }">Anton and Barbara just arrived</alert>
}
</result>
