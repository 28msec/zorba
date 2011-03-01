import module namespace z="http://www.zorba-xquery.com/header-dependencies" at "zorba_headers_dependencies.xqi";

import module namespace dot="http://www.zorba-xquery.com/modules/image/graphviz";

(: make doc has to be run prior to thins in order to generate the Doxygen XHTML's :)
(: this variable sets the destination of the Doxygen XHTML's :)
declare variable $doxygenCodePath as xs:string external;

(
z:fill-headersCollector($doxygenCodePath)
(:,z:list-headersCollector():)
, z:fill-dependenciesCollector($doxygenCodePath)
(:, z:list-dependenciesCollector() :)
,dot:dot(z:create-graph($doxygenCodePath),()) 
(:,z:create-graph($doxygenCodePath):) 
)