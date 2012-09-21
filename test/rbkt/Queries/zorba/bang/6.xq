let $works := <works>
  <employee name="1" />
  <employee name="2" />
</works>
return
  (($works/employee[2], $works/employee[1], $works/employee[2]) ! (@name) ! string())
