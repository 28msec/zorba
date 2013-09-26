copy $o := ["foo"]
modify (
  replace value of json $o(1) with "bar",
  replace value of json $o(1) with "bar2"
)
return $o
