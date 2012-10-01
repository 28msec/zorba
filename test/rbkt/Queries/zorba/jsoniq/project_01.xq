
let $obj := { "p1" : 1, "p2" : 2, "p3" : 3 }
return
  ( 
    jn:project($obj, "p1")
    ,
    jn:project($obj, ("p1", "p3"))
    ,
    jn:project($obj, "p5")
    ,
    jn:project($obj, ())
    ,
    jn:project($obj, ("p5", "p2"))
  )
