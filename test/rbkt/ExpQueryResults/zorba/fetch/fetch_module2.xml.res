xquery version "3.0";

(: Test module with external functions implemented in C++ :)
module namespace ext = "http://zorba-tests.28.io/modules/ext";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "1.0";

declare function ext:func() as xs:string external;
