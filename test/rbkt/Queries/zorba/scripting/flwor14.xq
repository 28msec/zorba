variable $mode := "option";

for $i in (1,2,3,4)
let $j :=
  switch ($mode)
  case "option" return 
  {
    $mode := "value";
    "option"
  }
  case "value" return 
  {
    $mode := "option";
    "value"
  }
  default return "default"
return
  <result>{$i, $j}</result>
