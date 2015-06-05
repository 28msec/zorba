xquery version "3.0";

(: Test module with external functions implemented in C++, with link libs :)
module namespace link = "http://zorba-tests.28.io/modules/link";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "1.0";

declare function link:xerces-func() as xs:integer external;

declare function link:our-func() as xs:integer external;

