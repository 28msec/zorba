xquery version "3.0";

module namespace vm = "http://zorba-tests.28.io/modules/ver";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "1.4.5";

declare variable $vm:value as xs:string := "version 1";

declare function vm:hello() as xs:string {
  "hello"
};

declare function vm:version() as xs:string {
  $vm:value
};
