import module namespace id = "http://zorba.io/modules/reference";

variable $el:=element {"elem"}{"elem"};
variable $attr:=attribute{"attr"}{"attr"};
variable $pi:=processing-instruction {"pi"}{"pi"};
variable $comm:=comment {"comment"};
variable $doc:=document {"document"};


id:dereference(id:reference($el)),
element {"attr"}{id:dereference(id:reference($attr))},
id:dereference(id:reference($pi)),
id:dereference(id:reference($comm)),
id:dereference(id:reference($doc))