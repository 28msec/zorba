(: Test module with external functions implemented in C++, with link libs :)
module namespace link = "http://zorba-tests.28msec.us/modules/link";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "1.0";

declare function link:xerces-func() as xs:integer external;

declare function link:our-func() as xs:integer external;

