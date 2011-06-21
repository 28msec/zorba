module namespace modB = "http://www.zorba-xquery.com/modules/B";

(: This module exists only to import a specific version of the "ver" module. :)

import module namespace vm = "http://www.zorba-xquery.com/modules/ver#2.0";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "1.0";

declare function modB:hello() as xs:string {
  vm:hello()
};

declare function modB:value() as xs:string {
  $vm:value
};