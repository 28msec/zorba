(: Test that contextual external functions work correctly in eval expressions. :)

module namespace extern = "urn:extern";

declare namespace ns2 = 'myns';


declare function extern:test() as xs:string
{
  eval {"
    declare function extern:bar() external;
    extern:bar()"
  }
};
