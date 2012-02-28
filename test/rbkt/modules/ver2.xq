module namespace vm = "http://www.flworfound.org/modules/ver";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.3";

declare variable $vm:value as xs:string := "version 2";

declare function vm:hello() as xs:string {
  "hello, v2"
};

declare function vm:version() as xs:string {
  $vm:value
};
