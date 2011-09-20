(:
 : Copyright 2006-2009 The FLWOR Foundation.
 :
 : Licensed under the Apache License, Version 2.0 (the "License");
 : you may not use this file except in compliance with the License.
 : You may obtain a copy of the License at
 :
 : http://www.apache.org/licenses/LICENSE-2.0
 :
 : Unless required by applicable law or agreed to in writing, software
 : distributed under the License is distributed on an "AS IS" BASIS,
 : WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 : See the License for the specific language governing permissions and
 : limitations under the License.
:)

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