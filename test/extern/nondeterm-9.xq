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
declare namespace extern = "urn:extern";
declare %ann:nondeterministic function extern:nondeterm() external;

declare %ann:nondeterministic function local:func()
{
  local:func2()
};

declare %ann:nondeterministic function local:func2()
{
  for $i in (1 to 2)
  return local:func3()
};

declare %ann:nondeterministic function local:func3()
{
  for $i in (1 to 5)
  return extern:nondeterm()
};

local:func()
