module namespace modA = "http://www.zorba-xquery.com/modules/A";

(: This module exists only to import a specific version of the "ver" module. :)

import module namespace vm = "http://www.zorba-xquery.com/modules/ver#1.0";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "1.0";

declare function modA:hello() as xs:string {
  vm:hello()
};

declare function modA:value() as xs:string {
  $vm:value
};