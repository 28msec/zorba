let $works := <works>
  <employee name="1" />
  <employee name="2" />
  <employee name="3" />
  <employee name="4" />
</works>
return
  ($works ! employee[4] ! preceding-sibling::*[1] ! string(@name))
