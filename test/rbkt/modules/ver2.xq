xquery version "3.0";

module namespace vm = "http://zorba-tests.28.io/modules/ver";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "2.3";

declare variable $vm:value as xs:string := "version 2";

declare function vm:hello() as xs:string {
  "hello, v2"
};

declare function vm:version() as xs:string {
  $vm:value
};
