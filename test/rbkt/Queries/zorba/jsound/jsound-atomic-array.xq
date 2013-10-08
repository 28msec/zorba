import module namespace jsv = "http://jsound.io/modules/validate"; 

let $instance := ["", "a", "abc"]

return
  jsv:jsd-valid("http://zorba-tests.28msec.us/jsound-schema",
    "a-string-array", $instance)
