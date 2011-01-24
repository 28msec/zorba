declare variable $seq := fn:doc("temp_events.xml");

for sliding window $w in $seq/stream/event 
  start  $s_curr when fn:true()
  only end next $next when $next/@time > $s_curr/@time + 3
return
  let $avg := fn:avg($w/@temp)
  where $avg * 2 lt xs:double($next/@temp) or $avg div 2 gt xs:double($next/@temp)
  return <alarm>Outlier detected. Event id:{data($next/@time)}</alarm>
