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


import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";

import module namespace mod2 = "http://www.mod2.ch/" at "file:///${CMAKE_CURRENT_BINARY_DIR}/collection2.xqlib";

declare namespace ann = "http://www.zorba-xquery.com/annotations"; 
declare namespace mod1 = "http://www.mod1.ch/";

declare %ann:sequential function local:test() 
{
  dml:insert-nodes-first(xs:QName("mod1:coll"), (<a>three</a>,<b>four</b>));
  dml:collection(xs:QName("mod1:coll"));
};

local:test()
