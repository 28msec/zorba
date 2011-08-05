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

module namespace mod1 = "http://www.zorba-xquery.com/mod1";

import module namespace mod2 = "http://www.zorba-xquery.com/mod2" at "file:///${CMAKE_CURRENT_BINARY_DIR}/fold_mod2.xq";

declare function mod1:wazaa() as element()?
{
  mod2:foo()
};
