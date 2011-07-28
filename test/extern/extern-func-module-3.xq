(: Test that contextual external functions work correctly in eval expressions. :)

module namespace extern = "urn:extern";

import module namespace refl = "http://www.zorba-xquery.com/modules/reflection";

declare function extern:test() as xs:string
{
  refl:eval("
    declare namespace ns2 = 'myns';
    declare function extern:bar() external;
    extern:bar()"
  )
};
