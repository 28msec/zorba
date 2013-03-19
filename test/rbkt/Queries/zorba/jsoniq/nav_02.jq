let $o := {
  "foo" : {
    "bar" : {
      "42." : 23
    }
  }
}
return $o.foo.bar("42.")
