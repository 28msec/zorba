import module namespace refl = "http://www.zorba-xquery.com/modules/reflection";

declare namespace extern = "urn:extern";

declare namespace ns2 = 'myns';


refl:eval("
  declare function extern:bar() external;
  extern:bar()
")
