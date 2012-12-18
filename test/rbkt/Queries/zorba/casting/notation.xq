declare namespace op = 'http://www.zorba-xquery.com/options/features';
declare namespace f = 'http://www.zorba-xquery.com/features';
declare option op:enable 'f:hof';

declare function local:clarkname($q as xs:NOTATION) as xs:string {
  $q
};

local:clarkname(xs:untypedAtomic("xs:integer"))
