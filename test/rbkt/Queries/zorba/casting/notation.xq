
declare function local:clarkname($q as xs:NOTATION) as xs:string {
  $q
};

local:clarkname(xs:untypedAtomic("xs:integer"))
