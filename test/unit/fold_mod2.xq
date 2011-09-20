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

module namespace mod2 = "http://www.zorba-xquery.com/mod2";

declare function mod2:bar() as xs:string external;

declare function mod2:someFunc() as element(data)?
{
  ()
};

declare function mod2:foo() as element(data)?
{
  let $res := mod2:bar()
  return 
    if ($res)
    then
      mod2:someFunc()
    else
      ()
};
