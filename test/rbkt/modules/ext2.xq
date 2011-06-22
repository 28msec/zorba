(: Test module with external functions implemented in C++ :)
module namespace ext = "http://www.zorba-xquery.com/modules/ext";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";

declare function ext:func() as xs:string external;
