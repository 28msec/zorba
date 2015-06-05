xquery version "3.0";

module namespace modB = "http://zorba-tests.28.io/modules/B";

(: This module exists only to import a specific version of the "ver" module. :)

import module namespace vm = "http://zorba-tests.28.io/modules/ver#2.0";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "1.0";

declare function modB:hello() as xs:string {
  vm:hello()
};

declare function modB:value() as xs:string {
  $vm:value
};