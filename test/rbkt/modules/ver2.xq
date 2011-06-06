module namespace vm = "http://www.zorba-xquery.com/modules/ver";

declare namespace ver = "http://www.zorba-xquery.com/versioning";
declare option ver:version "2.3";

declare variable $vm:value as xs:string := "version 2";

declare function vm:hello() as xs:string {
  "hello, v2"
};

declare function vm:version() as xs:string {
  $vm:value
};
