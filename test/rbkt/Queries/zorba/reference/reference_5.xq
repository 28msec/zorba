import module namespace id = "http://www.zorba-xquery.com/modules/node-reference";
let $temp:=<root>temp</root> 
return id:node-by-reference(id:node-reference($temp))
