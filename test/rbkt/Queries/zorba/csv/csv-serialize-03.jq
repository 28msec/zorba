import module namespace csv = "http://zorba.io/modules/json-csv";

let $values := (
  {
    "f,i,r,s,t" : "o,n,e",
    "s,e,c,o,n,d" : "t,w,o",
    "t,h,i,r,d" : "t,h,r,e,e"
  },
  {
    "f,i,r,s,t" : "f,o,u,r",
    "s,e,c,o,n,d" : "f,i,v,e",
    "t,h,i,r,d" : "s,i,x"
  }
)
let $options := { "field-names" : [ "f,i,r,s,t", "s,e,c,o,n,d", "t,h,i,r,d" ] }
return string-join( csv:serialize( $values, $options ), "" )

(: vim:set syntax=xquery et sw=2 ts=2: :)
