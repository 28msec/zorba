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

import module namespace guestbook = "http://www.28msec.com/templates/guestbook/guestbook" at "file:///@CMAKE_CURRENT_BINARY_DIR@/guestbook.xq";

import module namespace refl = "http://www.zorba-xquery.com/modules/reflection";

guestbook:init(), refl:eval("guestbook:list()")
