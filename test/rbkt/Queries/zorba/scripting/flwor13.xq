
variable $mode := "option";

for $i in (1,2,3,4)
return
  switch ($mode)
  case "option" return 
  {
    fn:trace($mode, "option mode");
    $mode := "value";
    'option'
  }
  case "value" return 
  {
    fn:trace($mode, "value mode");
    $mode := "option";
    'value'
  }
  default return "default"

