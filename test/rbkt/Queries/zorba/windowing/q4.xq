declare variable $timesequence := fn:doc("temp_events.xml");

let $MAX_DIFF := 2

for sliding window $w in $timesequence/stream/event 
  start $s_curr at $s_pos previous $s_prev
  when ($s_curr/@time ne $s_prev/@time) or (empty($s_prev))
  only end next $e_next 
  when $e_next/@time - $s_curr/@time gt $MAX_DIFF
return 
  avg( $w/@temp )
