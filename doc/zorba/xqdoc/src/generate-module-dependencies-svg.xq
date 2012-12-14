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

import module namespace z="http://www.zorba-xquery.com/module-dependencies" at "zorba_module_dependencies.xqy";

import module namespace dot="http://www.zorba-xquery.com/modules/image/graphviz";

(: make xqdoc has to be run prior to thins in order to generate the XQDoc XML's :)
(: this variable sets the destination of the XQDoc XML's :)
declare variable $ZorbaBuildFolder external;

(
z:create-collections($ZorbaBuildFolder)
, dot:dot(z:create_graph(),())
(:, z:create_graph():)
,z:delete-collections()
)