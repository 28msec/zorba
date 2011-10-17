import module namespace id = "http://www.zorba-xquery.com/modules/node-reference";

variable $el:=element {"elem"}{"elem"};
variable $attr:=attribute{"attr"}{"attr"};
variable $pi:=processing-instruction {"pi"}{"pi"};
variable $comm:=comment {"comment"};
variable $doc:=document {"document"};


id:node-by-reference(id:node-reference($el)),
element {"attr"}{id:node-by-reference(id:node-reference($attr))},
id:node-by-reference(id:node-reference($pi)),
id:node-by-reference(id:node-reference($comm)),
id:node-by-reference(id:node-reference($doc))