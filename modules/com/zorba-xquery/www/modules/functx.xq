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

(:~
 : Only Funcx functions used inside Zorba
 :
 : @version 1.0 
 :)
module namespace zfunctx = "http://www.zorba-xquery.com/modules/functx";

(:~
 : The functx:are-distinct-values function returns true if all of the values
 : in the sequence are distinct; i.e., no one value appears more than once in
 : the sequence. Distinctness is based on type equality.
 :
 : @param $seq The sequence of atomic values to be checked.
 : @return True if all are distinct, false if at least two value are the same.
 :)
declare function zfunctx:are-distinct-values 
  ( $seq as xs:anyAtomicType* )  as xs:boolean 
{
   count(distinct-values($seq)) = count($seq)
};