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

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare variable $sequence := (65 to 90);
declare variable $var := 1;

declare %ann:sequential function local:foo()
{
  $var := $var + 1;
  $var
};


declare %ann:sequential function local:bar()
{
  for $i in (1 to 10)
  return
    {
      variable $rand := local:foo();

      $sequence[$rand]
    }
};


local:bar()
