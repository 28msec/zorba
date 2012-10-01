let $works := <works>
  <employee name="1" />
  <employee name="2">
    <hours>10</hours>
    <hours>20</hours>
  </employee>
</works>
return
  ($works ! employee[2] ! hours[2] ! number())
