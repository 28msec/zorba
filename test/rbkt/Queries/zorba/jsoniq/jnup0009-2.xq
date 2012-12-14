copy $o := ["foo"]
modify (
  replace json value of $o(1) with "bar",
  replace json value of $o(1) with "bar2"
)
return $o