module namespace extern = "urn:extern";

declare namespace ns2 = "myns";
declare function extern:bar() external;


declare function extern:test() as xs:string
{
  extern:bar()
};
