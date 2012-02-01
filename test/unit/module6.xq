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

module namespace mod6 = "http://www.mod6.com/";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

import schema namespace s = "http://www.zorba-xquery.com/schemas/simple" at "file:///${CMAKE_CURRENT_BINARY_DIR}/schema1.xsd";

declare collection mod6:coll01 as document-node(element(s:product))*;
declare collection mod6:coll02 as document-node(element(*, s:ProductType))*;
declare collection mod6:coll03 as document-node(schema-element(s:product))*;

declare collection mod6:coll04 as element(s:product)*;
declare collection mod6:coll05 as element(*, s:ProductType)*;
declare collection mod6:coll06 as schema-element(s:product)*;

declare collection mod6:coll07 as attribute(s:zip-code)*;
declare collection mod6:coll08 as attribute(*, s:ZipType)*;
declare collection mod6:coll09 as schema-attribute(s:zip-code)*;

declare collection mod6:coll10 as text();
declare collection mod6:coll11 as text()?;
declare collection mod6:coll12 as text()+;

