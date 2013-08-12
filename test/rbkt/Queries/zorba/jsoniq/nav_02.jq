let $o := {
  "foo" : {
    "bar" : {
      "42." : 23
    }
  }
}
let $bar := "bar"
return $o.foo.$bar."42."
