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

declare variable $x := 42;

declare function local:f($n) 
{
  variable $x := $n - 1;

  if ($n eq 0)
  then 0
  else { variable $y := local:f($x); ($y + $x) }
};


{
  variable $y := local:f(4);
  variable $z := local:f(3);
  $y + $z + $x
}
