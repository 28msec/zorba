(: Catching Everything :)

declare namespace err="http://www.w3.org/2005/xqt-errors";
let $x := 1 div 0
return
  try { 
    $x 
  } catch * { "This catch clause won't fire." }
