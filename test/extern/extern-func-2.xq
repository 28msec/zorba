declare namespace extern = "urn:extern";

declare namespace ns2 = 'myns';


eval {"
  declare function extern:bar() external;
  extern:bar()
"}
