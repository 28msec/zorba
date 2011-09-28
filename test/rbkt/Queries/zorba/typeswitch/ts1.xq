declare function local:typename ($x) as xs:string {
typeswitch ($x)
  case $a as xs:integer return "integer"
  case xs:string return "string"
  default return "?"
};

local:typename (1), local:typename ("x"), local:typename (<a/>)
