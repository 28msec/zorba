declare namespace extern = "urn:extern";

eval {"
  declare namespace ns2 = 'myns';
  declare function extern:bar() external;
  extern:bar()
"}
