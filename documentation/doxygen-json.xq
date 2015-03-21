module namespace c = "http://www.zorba-xquery.com/doxygen/json";
declare namespace xqdoc = "http://www.xqdoc.org/1.0";

declare copy-namespaces no-preserve, inherit;

declare function c:json($nodes as node()*, $version as xs:string, $api as xs:string)
{ 
  {
    "api": $api,
    "name": string($nodes//compoundname/text()),
    "description": $nodes//detaileddescription//*[local-name() ne "htmlonly"]/text() 
  }
};

