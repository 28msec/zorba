let $x := 1 div 0
return
  try { 
    $x 
  } catch (*) { "This catch clause won't fire." }
