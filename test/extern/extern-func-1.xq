
import module namespace refl = "http://www.zorba-xquery.com/modules/reflection";

declare namespace extern = "urn:extern";

refl:eval("
  declare namespace ns2 = 'myns';
  declare function extern:bar() external;
  extern:bar()
")
