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

import module namespace mod1 = "http://www.mod1.ch/" at "file:///${CMAKE_CURRENT_BINARY_DIR}/collection1.xqlib";

import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare %ann:sequential function local:test() 
{
  ddl:create($mod1:coll);
  dml:insert-nodes-last($mod1:coll, (<a>one</a>,<b>two</b>));
  dml:collection($mod1:coll);
};

local:test()
