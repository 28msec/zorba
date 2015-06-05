xquery version "3.0";

module namespace modA = "http://zorba-tests.28.io/modules/A";

(: This module exists only to import a specific version of the "ver" module. :)

import module namespace vm = "http://zorba-tests.28.io/modules/ver#1.0";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "1.0";

declare function modA:hello() as xs:string {
  vm:hello()
};

declare function modA:value() as xs:string {
  $vm:value
};