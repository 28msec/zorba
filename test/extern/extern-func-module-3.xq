(: Test that contextual external functions work correctly in eval expressions. :)

module namespace extern = "urn:extern";


declare function extern:test() as xs:string
{
  eval {"
    declare namespace ns2 = 'myns';
    declare function extern:bar() external;
    extern:bar()"
  }
};
