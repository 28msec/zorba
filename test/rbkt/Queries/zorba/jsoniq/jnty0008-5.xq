let $a := (["foo"], ["bar"])
return
  replace json value of $a(1) with "foo"
